#include "pro_main.h"
#include "pro_window.h"
#include "pro_window_signals.h"

struct _Pro_Window_Private
{
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_COLOR fill_color;

    int w , h, quit;
    float fps;
};

static void pro_window_init( Pro_Window* win, int w, int h );
static void pro_window_set_size( Pro_Window* win, int w, int h);
void pro_window_signals_init( Pro_Window* win ); /* not static */

Pro_Window* pro_window_new( int w, int h )
{
    Pro_Window* win = PRO_NEW( Pro_Window );

    win->priv = PRO_NEW( Pro_Window_Private );

    pro_window_signals_init( win );
    pro_window_init( win, w, h );

    return win;
}

void pro_window_init( Pro_Window* win, int w, int h )
{
    Pro_Window_Private* priv = win->priv;

    priv->display = al_create_display( w, h );
    if( !priv->display ) PRO_ERROR("could not create display");

    priv->event_queue = al_create_event_queue();
    if( !priv->event_queue ) PRO_ERROR("could not create event queue");

    pro_window_set_size( win, w, h);
    priv->fps = 60.0;

    priv->fill_color = al_map_rgb( PRO_WINDOW_COLOR );

    priv->timer = al_create_timer( 1.0 / priv->fps );

    al_register_event_source( priv->event_queue, al_get_display_event_source( priv->display ) );
    al_register_event_source( priv->event_queue, al_get_timer_event_source( priv->timer ) );

    pro_window_redraw( win );
}

void pro_window_run( Pro_Window* win )
{
    pro_signal_emit( win->signal->run, win );

    Pro_Window_Private* priv = win->priv;
    al_start_timer( priv->timer );

    priv->quit = 0;

    while( pro_window_is_open( win ) )
    {
        ALLEGRO_EVENT* event = PRO_NEW( ALLEGRO_EVENT );
        al_wait_for_event( priv->event_queue, event );

        if ( event->type == ALLEGRO_EVENT_TIMER )
            pro_window_redraw( win );
        if( event->type == ALLEGRO_EVENT_DISPLAY_CLOSE )
            pro_window_quit( win );
    }

}

void pro_window_redraw( Pro_Window* win )
{
    Pro_Window_Private* priv = win->priv;
    al_clear_to_color( priv->fill_color );

    pro_signal_emit( win->signal->paint, win );
    al_flip_display();
}

void pro_window_destroy( Pro_Window* win )
{
    Pro_Window_Private* priv = win->priv;

    al_destroy_timer( priv->timer );
    al_destroy_display( priv->display );
    al_destroy_event_queue( priv->event_queue );

    PRO_DELETE( win->priv );
    PRO_DELETE( win );
}

void pro_window_set_size(Pro_Window* win, int w, int h)
{
    Pro_Window_Private* priv = win->priv;
    priv->w = w; priv->h = h;
}

int pro_window_get_width( Pro_Window* win )
{
    return win->priv->w;
}

int pro_window_get_height( Pro_Window* win )
{
    return win->priv->h;
}

ALLEGRO_DISPLAY* pro_window_get_display( Pro_Window* win )
{
    return win->priv->display;
}

void pro_window_set_fps( Pro_Window* win, float fps )
{
    Pro_Window_Private* priv = win->priv;
    priv->fps = fps;
    al_set_timer_speed( priv->timer, 1.0 / priv->fps );
}

float pro_window_get_fps( Pro_Window* win )
{
    return win->priv->fps;
}

void pro_window_set_fill_color( Pro_Window* win, ALLEGRO_COLOR color )
{
    win->priv->fill_color = color;
}

ALLEGRO_COLOR pro_window_get_fill_color( Pro_Window* win )
{
    return win->priv->fill_color;
}

void pro_window_quit( Pro_Window* win )
{
    win->priv->quit = 1;
    pro_signal_emit( win->signal->quit, win );
}

int pro_window_is_open( Pro_Window* win )
{
    return !win->priv->quit;
}

void pro_window_return_target( Pro_Window* win )
{
    al_set_target_bitmap( al_get_backbuffer( win->priv->display ) );
}

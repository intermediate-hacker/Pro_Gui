#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "pro_window.h"
#include "pro_window_signals.h"

ALLEGRO_BITMAP* bmp;
int bmp_w = 30, bmp_h = 30, bmp_x = 40, bmp_y = 40;
int bmp_dx = 1, bmp_dy = 1;

void paint_two( Pro_Window* win )
{
    if( bmp_x < 0 || bmp_x > 640 - bmp_w )
     bmp_dx = -bmp_dx;

    if( bmp_y < 0 || bmp_y > 480 - bmp_h )
     bmp_dy = -bmp_dy;

    bmp_x += bmp_dx;
    bmp_y += bmp_dy;

    al_draw_bitmap(bmp, bmp_x, bmp_y, 0);

}

int main( int argc, char* argv[] )
{
    al_init();

    Pro_Window* win = pro_window_new(640,480);

    bmp = al_create_bitmap( 30, 30 );
    al_set_target_bitmap( bmp );
    al_clear_to_color( al_map_rgb( 255, 0, 0 ) );
    pro_window_return_target( win );

    pro_signal_connect( win, win->signal->paint, paint_two );

    pro_window_set_fps( win, 60 );

    pro_window_run(win);


    return EXIT_SUCCESS;
}

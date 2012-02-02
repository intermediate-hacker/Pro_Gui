#include "pro_window.h"

//8typedef void (*Pro_Window_Signal)(Pro_Window*);

struct _Pro_Window_Signals
{
    void PRO_SIGNAL( paint, Pro_Window* );
    int paint_count;
};

void pro_window_signals_init( Pro_Window* win )
{
    win->signal = PRO_NEW( Pro_Window_Signals );
    Pro_Window_Signals* signal = win->signal;

    signal->paint_count = 0;
    signal->paint = NULL;
}

void pro_window_paint_connect( Pro_Window* win, void(*func)(Pro_Window*) )
{
    Pro_Window_Signals* signal = win->signal;

    if( func ) signal->paint = func;
    if ( signal->paint_count < PRO_SIGNAL_MAX ) signal->paint_count++;
}

int pro_window_paint_count( Pro_Window* win )
{
    return win->signal->paint_count;
}

void pro_window_paint_emit( Pro_Window* win )
{
    pro_signal_emit( win->signal->paint, win );
}

#include "pro_window.h"
#include "pro_window_signals.h"

void pro_window_signals_init( Pro_Window* win )
{
    win->signal = PRO_NEW( Pro_Window_Signals );
    Pro_Window_Signals* signal = win->signal;

    signal->paint = NULL;
    signal->quit = NULL;
    signal->run = NULL;
}

#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "pro_window.h"
#include "pro_window_signals.h"


void paint_two( Pro_Window* obj )
{
    static int i = 0;
    printf("-------- %i \n", i++);
}

int main( int argc, char* argv[] )
{
    al_init();
    Pro_Window* win = pro_window_new(640,480);

    pro_signal_connect( win, win->signal->paint, paint_two );

    pro_window_set_fps( win, 1 );

    pro_window_run(win);


    return EXIT_SUCCESS;
}

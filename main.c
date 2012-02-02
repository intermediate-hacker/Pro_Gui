#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "pro_window.h"


void paint_two( Pro_Window* obj )
{
    static int i = 0;
    printf("-------- %i \n", i++);
}

int main( int argc, char* argv[] )
{
    al_init();
    Pro_Window* win = pro_window_new(640,480);

    pro_window_paint_connect( win, paint_two );

    pro_window_set_fps( win, 20 );

    pro_window_run(win);


    return EXIT_SUCCESS;
}

/**
* @file pro_window.h
* @Author Muhammad Ahmad Tirmazi (smat1995@gmail.com)
* @date February 1, 2012
* @brief The Main Window Structure
*/

#ifndef PRO_WINDOW_H
#define PRO_WINDOW_H

#include <stdlib.h>
#include <allegro5/allegro.h>
#include "pro_main.h"

typedef struct _Pro_Window Pro_Window;
typedef struct _Pro_Window_Private Pro_Window_Private;
typedef struct _Pro_Window_Signals Pro_Window_Signals;

/** the main window structure **/
struct _Pro_Window
{
    Pro_Window_Private* priv;
    Pro_Window_Signals* signal;
};

/** Pro_Window constructor
    @param [in] w width of the window
    @param [in] h height of the window
 **/
Pro_Window* pro_window_new( int w, int h );

/** Begins the window main-loop **/
void pro_window_run( Pro_Window* win );
/** Pro_Window destructor **/
void pro_window_destroy( Pro_Window* win );

/** Redraws the window, calls the paint signals **/
void pro_window_redraw( Pro_Window* win );

/** @retval 1 if window is open, 0 if window has quit **/
int pro_window_is_open( Pro_Window* win );
/** Quits the window main loop **/
void pro_window_quit( Pro_Window* win );

/** @retval width of the window. **/
int pro_window_get_width( Pro_Window* win );
/**  @retval height of the window **/
int pro_window_get_height( Pro_Window* win );

/** @retval pointer to the ALLEGRO_DISPLAY being used. **/
ALLEGRO_DISPLAY* pro_window_get_display( Pro_Window* win );

/** @param [in] fps framerate for the window **/
void pro_window_set_fps( Pro_Window* win, float fps );
/** @retval frame rate per second of the window **/
float pro_window_get_fps( Pro_Window* win );

/** @param [in]] color used to fill the window **/
void pro_window_set_fill_color( Pro_Window* win, ALLEGRO_COLOR color );
/** @retval color used to fill the window **/
ALLEGRO_COLOR pro_window_get_fill_color( Pro_Window* win );

/** sets al_target_bitmap back to Pro_Window's back buffer **/
void pro_window_return_target( Pro_Window* win );

#endif /* PRO_WINDOW_H */

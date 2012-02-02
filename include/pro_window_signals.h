/** @file pro_window_signals.h
*   @author Muhammad Ahmad Tirmazi (smat1995@gmail.com)
*   @date February 02, 2012
*   @brief seperate header for Pro_Window's signals
**/

#ifndef PRO_WINDOW_SIGNALS_H
#define PRO_WINDOW_SIGNALS_H

struct _Pro_Window_Signals
{
    void PRO_SIGNAL( paint, Pro_Window* );
    void PRO_SIGNAL( quit, Pro_Window* );
    void PRO_SIGNAL( run, Pro_Window* );
};

#endif /* PRO_WINDOW_SIGNALS_H */

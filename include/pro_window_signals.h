#ifndef PRO_WINDOW_SIGNALS_H
#define PRO_WINDOW_SIGNALS_H

struct _Pro_Window_Signals
{
    void PRO_SIGNAL( paint, Pro_Window* );
    void PRO_SIGNAL( quit, Pro_Window* );
    void PRO_SIGNAL( run, Pro_Window* );
};

#endif /* PRO_WINDOW_SIGNALS_H */

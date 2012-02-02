/**
* @file pro_signal.h
* @Author Muhammad Ahmad Tirmazi (smat1995@gmail.com)
* @date February 1, 2012
* @brief Signals, for events and stuff.
**/

#ifndef PRO_SIGNAL_H
#define PRO_SIGNAL_H

/** Macro for error handling **/
#define PRO_ERROR( msg ) fprintf( stderr, "error: %s \n", msg )

/** Max slots for a signal **/
#define PRO_SIGNAL_MAX 5

typedef void (*Pro_Signal)(void*);

#define PRO_SIGNAL( func, param ) (*func)(param)

/** macro function for emitting signals
*   @param [in] signal a pointer to the signal function.
*   @param [in] args arguments for the function call;
**/
#define pro_signal_emit( signal , args ) (*signal)(args)
#define pro_signal_connect( obj, signal, func ) if ( func != NULL){ signal = func; }

#endif /* PRO_SIGNAL_H */

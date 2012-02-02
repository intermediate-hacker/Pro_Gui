/**
* @file pro_macro.h
* @Author Muhammad Ahmad Tirmazi (smat1995@gmail.com)
* @date February 1, 2012
* @brief Utility Macros for convenience
**/

#ifndef PRO_MACRO_H
#define PRO_MACRO_H

/** Macro for object construction **/
#define PRO_NEW( obj ) (obj*) malloc( sizeof( obj ) )
/** Macro for object destruction **/
#define PRO_DELETE( obj ) free( obj )

#endif /* PRO_MACRO_H */

/** @file pro_platform.h
*   @Author Muhammad Ahmad Tirmazi
*   @date February 02, 2012
*   @brief platform dependent defines **/


#ifndef PRO_PLATFORM_H
#define PRO_PLATFORM_H

#if defined( WIN32 ) || defined( _WIN32 )

#include <windows.h>
#define PRO_SYS_COLOR GetSysColor( COLOR_BTNFACE )
#define PRO_WINDOW_COLOR\
 GetRValue( PRO_SYS_COLOR ), GetGValue( PRO_SYS_COLOR ), GetBValue( PRO_SYS_COLOR )

#else
#define PRO_WINDOW_COLOR 209,209,209
#endif /* WIN32 */

#endif /* PRO_PLATFORM_H */

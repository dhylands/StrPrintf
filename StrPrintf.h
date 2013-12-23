/****************************************************************************
*
*   Copyright (c) 2013 Dave Hylands     <dhylands@gmail.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 2 as
*   published by the Free Software Foundation.
*
*   Alternatively, this software may be distributed under the terms of BSD
*   license.
*
*   See README and COPYING for more details.
*
****************************************************************************/
/**
*
*  @file    StrPrintf.h
*
*  @brief   Implementation of a re-entrant printf function.
*
****************************************************************************/

// ---- Include Files -------------------------------------------------------

#if !defined( STRPRINTF_H )
#define STRPRINTF_H

#include <stddef.h>
#include <stdarg.h>
#include <string.h>

/**
 * Pointer to a function which outputs a single character. This function
 * is called by the strXPrintf()/vStrXPrintf() functions to output a
 * character.
 */

typedef int (*StrXPrintfFunc)(  void *outParm, int ch);

int StrPrintf(char *outStr, int maxLen, const char *fmt, ...);
int vStrPrintf(char *outStr, int maxLen, const char *fmt, va_list args);

int StrXPrintf(StrXPrintfFunc func, void *userParm, const char *fmt, ...);
int vStrXPrintf(StrXPrintfFunc func, void *userParm, const char *fmt, va_list args);

#endif // STRPRINTF_H

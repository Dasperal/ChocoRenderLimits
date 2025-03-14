//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
// Copyright(C) 2014-2017 RestlessRodent
// Copyright(C) 2018-2023 Julia Nechaevskaya
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//      Miscellaneous.
//    


#ifndef __M_MISC__
#define __M_MISC__

#include <stdio.h>
#include <stdarg.h>

#include "doomtype.h"

#ifdef _WIN32
wchar_t *M_ConvertUtf8ToWide(const char *str);
#endif
char *M_ConvertUtf8ToSysNativeMB(const char *str);
char *M_ConvertSysNativeMBToUtf8(const char *str);

FILE *M_fopen(const char *filename, const char *mode);
int M_remove(const char *path);
int M_rename(const char *oldname, const char *newname);
char *M_getenv(const char *name);
boolean M_WriteFile(const char *name, void *source, int length);
int M_ReadFile(char *name, byte **buffer);
void M_MakeDirectory(const char *dir);
char *M_TempFile(char *s);
boolean M_FileExists(const char *file);
char *M_FileCaseExists(const char *file);
long M_FileLength(FILE *handle);
boolean M_StrToInt(const char *str, int *result);
void M_ExtractFileBase(char *path, char *dest);
void M_ForceUppercase(char *text);
void M_ForceLowercase(char *text);
char *M_StrCaseStr(char *haystack, char *needle);
char *M_StringDuplicate(const char *orig);
boolean M_StringCopy(char *dest, const char *src, size_t dest_size);
boolean M_StringConcat(char *dest, const char *src, size_t dest_size);
char *M_StringReplace(const char *haystack, const char *needle,
                      const char *replacement);
char *M_StringJoin(const char *s, ...);
boolean M_StringStartsWith(const char *s, const char *prefix);
boolean M_StringEndsWith(const char *s, const char *suffix);
int M_vsnprintf(char *buf, size_t buf_len, const char *s, va_list args);
int M_snprintf(char *buf, size_t buf_len, const char *s, ...);
char *M_OEMToUTF8(const char *ansi);

#endif


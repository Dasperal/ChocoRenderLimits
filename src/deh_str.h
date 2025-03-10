//
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
//
// Dehacked string replacements
//

#ifndef DEH_STR_H
#define DEH_STR_H

#include <stdio.h>

// Used to do dehacked text substitutions throughout the program

char *DEH_String(char *s);
void DEH_printf(char *fmt, ...);
void DEH_fprintf(FILE *fstream, char *fmt, ...);
void DEH_snprintf(char *buffer, size_t len, char *fmt, ...);
void DEH_AddStringReplacement(char *from_text, char *to_text);


#if 0
// Static macro versions of the functions above

#define DEH_String(x) (x)
#define DEH_printf printf
#define DEH_fprintf fprintf
#define DEH_snprintf snprintf

#endif

#endif /* #ifndef DEH_STR_H */


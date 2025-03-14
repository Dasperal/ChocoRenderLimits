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
//	Main program, simply calls D_DoomMain high level loop.
//

#include "config.h"

#include <stdio.h>

#include "SDL.h"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#include "doomtype.h"
#include "i_system.h"
#include "m_argv.h"


#ifdef _WIN32
// -----------------------------------------------------------------------------
// CRL_CreateWindowsConsole
// [JN] Creates console output Window. For Windows OS only.
// -----------------------------------------------------------------------------

void CRL_CreateWindowsConsole (void)
{
    CONSOLE_FONT_INFOEX cfi;    // [JN] Purely to shut up compiler warning.

    // Allocate console.
    AllocConsole();

    // Head text outputs.
    freopen("CONIN$", "r",stdin); 
    freopen("CONOUT$","w",stdout); 
    freopen("CONOUT$","w",stderr); 

    // Set a proper codepage.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Set console font to "Consolas".
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 16;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
#endif

//
// D_DoomMain()
// Not a globally visible function, just included for source reference,
// calls all startup code, parses command line options.
//

void D_DoomMain (void);

int main(int argc, char **argv)
{
    // save arguments

    myargc = argc;
    myargv = argv;

    M_FindResponseFile();

#ifdef _WIN32
    // [JN] Create a console output on Windows.
    if (M_CheckParm ("-console"))
    {
        CRL_CreateWindowsConsole();
    }
#endif

    // start doom

    D_DoomMain ();

    return 0;
}


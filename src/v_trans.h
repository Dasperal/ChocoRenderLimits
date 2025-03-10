// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: v_video.h,v 1.9 1998/05/06 11:12:54 jim Exp $
//
//  BOOM, a modified and improved DOOM engine
//  Copyright (C) 1999 by
//  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 
//  02111-1307, USA.
//
// DESCRIPTION:
//  Gamma correction LUT.
//  Color range translation support
//  Functions to draw patches (by post) directly to screen.
//  Functions to blit a block to the screen.
//
//-----------------------------------------------------------------------------


#pragma once

#include "doomtype.h"


enum
{
    CR_DARK,
    CR_THIRDSATURTION,
    CR_MONOCHROME,

    CR_RED,
    CR_DARKRED,
    CR_GREEN,
    CR_DARKGREEN,
    CR_OLIVE,
    CR_BLUE,
    CR_BLUE2,
    CR_DARKBLUE,
    CR_YELLOW,
    CR_ORANGE,
    CR_WHITE,
    CR_GRAY,
    CR_LIGHTGRAY,
    CR_DARKGRAY,
    CR_TAN,
    CR_BROWN,
    CR_ALMOND,
    CR_KHAKI,
    CR_PINK,
    CR_BURGUNDY,

    // Doom (colored blood and slider gem)
    CR_RED2BLUE, // Terminator - don't override tablified colors starting from this line
    CR_RED2GREEN,
    CR_RED2GRAY,

    CRMAX,
    CR_NONE,
    CR__STOP = CR_RED2BLUE
};

extern byte  *cr[CRMAX];
extern char **crstr;

#define cr_esc '~'

int V_GetPaletteIndex(byte *palette, int r, int g, int b);
byte V_Colorize (byte *playpal, int cr, byte source, boolean keepgray109);

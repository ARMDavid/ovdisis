/*
** ggi_visual_mouse.c
**
** Copyright 1999 Christer Gustavsson <cg@nocrew.org>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**  
** Read the file COPYING for more information.
**
*/

#include <ggi/ggi.h>
#include <stdio.h>

#include "ggi_visual.h"
#include "ggi_visual_mouse.h"


static char saved[2000]; /* FIXME: Calculate size and put in private type */
static int  saved_x = 0;
static int  saved_y = 0;


/*
** Description
** Save background before drawing mouse
*/
void
ggi_visual_save_mouse_bg (void * private,
			  int    x,
			  int    y) {
  ggiGetBox(VISUAL_T(private), x, y, 16, 16, saved);
  saved_x = x;
  saved_y = y;
}


/*
** Description
** Restore mouse background
*/
void
ggi_visual_restore_mouse_bg (void * private) {
  ggiPutBox(VISUAL_T(private), saved_x, saved_y, 16, 16, saved);
}

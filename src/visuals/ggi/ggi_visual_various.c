/*
** ggi_visual_various.c
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
#include "ovdisis.h"

int
ggi_visual_get_pixel (void * fb,
		      int    x,
		      int    y) {
  fprintf(stderr, "Implement ggi_visual_get_pixel\n");
  return 0;
}


void
ggi_visual_put_pixel (void * vis,
		      int    x,
		      int    y,
		      int    c) {
  ggi_color col1 = { 0, 0, 0xffff, 0xffff };

  ggiPutPixel(VISUAL_T(vis), x, y, ggiMapColor(VISUAL_T(vis), &col1));
}


void
ggi_visual_hline (void * vis,
		  int    x1,
		  int    x2,
		  int    y,
		  int    c) {
  ggi_color col1 = { 0xffff, 0, 0, 0xffff };

  ggiSetGCForeground(VISUAL_T(vis), ggiMapColor(VISUAL_T(vis), &col1));
  ggiDrawHLine(VISUAL_T(vis), x1, y, x2 - x1 + 1);
}


void
ggi_visual_line (void * vis,
		 int    x1,
		 int    y1,
		 int    x2,
		 int    y2,
		 int    c) {
  ggi_color col1 = { 0, 0xffff, 0, 0xffff };

  ggiSetGCForeground(VISUAL_T(vis), ggiMapColor(VISUAL_T(vis), &col1));
  ggiDrawLine(VISUAL_T(vis), x1, y1, x2, y2);
}


void
ggi_visual_bitblt (VDI_Workstation * vwk,
		   int               mode,
		   RECT *            srccor,
		   RECT *            dstcor,
		   MFDB *            src,
		   MFDB *            dst) {
  fprintf(stderr, "Implement ggi_visual_bitblt\n");
}


void
ggi_visual_bitbltt (VDI_Workstation * vwk,
		    int               mode,
		    int               fgcol,
		    int               bgcol,
		    RECT *            srccor,
		    RECT *            dstcor,
		    MFDB *            src,
		    MFDB *            dst) {
  fprintf(stderr, "Implement ggi_visual_bitbltt\n");
}


void
ggi_visual_put_char (void * vis,
		     int    x,
		     int    y,
		     int    col,
		     int    ch) {
  ggi_color col1 = { 0xffff, 0xffff, 0xffff, 0xffff };

  ggiSetGCForeground(VISUAL_T(vis), ggiMapColor(VISUAL_T(vis), &col1));
  ggiPutc(VISUAL_T(vis), x, y, ch);
}


void
ggi_visual_set_font (void * fb,
		     void * data,
		     int    width,
		     int    height) {
  fprintf(stderr, "Implement ggi_visual_set_font\n");
}


void
ggi_visual_inquire (void *        vis,
		    Visual_Attr * attr) {
  ggi_mode graphical_mode;

  ggiGetMode(VISUAL_T(vis), &graphical_mode);

  attr->x_res = graphical_mode.virt.x;
  attr->y_res = graphical_mode.virt.y;
  attr->palette_size = 1 << GT_DEPTH(graphical_mode.graphtype);
  attr->number_of_colours = 1 << GT_DEPTH(graphical_mode.graphtype);
  attr->bits_per_pixel = GT_DEPTH(graphical_mode.graphtype);
}


/*
 * vdibind.h
 *
 * Copyright 1998 Tomas Berndtsson <tomas@nocrew.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *  
 * Read the file COPYING for more information.
 *
 */

#ifndef _VDIBIND_H_
#define _VDIBIND_H_


typedef struct
{
    short contrl[15];
    short intin[132];
    short ptsin[145];
    short intout[140];
    short ptsout[145];
} VDIPARBLK;

typedef struct
{
    short *contrl;
    short *intin;
    short *ptsin;
    short *intout;
    short *ptsout;
} VDIPB;


/****** Attribute definitions *****************************************/

#define IP_HOLLOW   0
#define IP_1PATT    1
#define IP_2PATT    2
#define IP_3PATT    3
#define IP_4PATT    4
#define IP_5PATT    5
#define IP_6PATT    6
#define IP_SOLID    7


/* gsx modes */

#define MD_REPLACE  1
#define MD_TRANS    2
#define MD_XOR      3
#define MD_ERASE    4


/* gsx styles */

#define FIS_HOLLOW  0
#define FIS_SOLID   1
#define FIS_PATTERN 2
#define FIS_HATCH   3
#define FIS_USER    4


/* bit blt rules */

#define ALL_WHITE   0
#define S_AND_D     1
#define S_AND_NOTD  2
#define S_ONLY      3
#define NOTS_AND_D  4
#define D_ONLY      5
#define S_XOR_D     6
#define S_OR_D      7
#define NOT_SORD    8
#define NOT_SXORD   9
#define NOT_D      10
#define S_OR_NOTD  11
#define NOT_S      12
#define NOTS_OR_D  13
#define NOT_SANDD  14
#define ALL_BLACK  15


/* linetypes */

#define SOLID       1
#define LONGDASH    2
#define DOT         3
#define DASHDOT     4
#define DASH        5
#define DASH2DOT    6
#define USERLINE    7

#define SQUARE      0
#define ARROWED     1
#define ROUND       2

#define M_DOT       1
#define M_PLUS      2
#define M_ASTERISK  3
#define M_SQUARE    4
#define M_CROSS     5
#define M_DIAMOND   6


/* text effect bitfields */

#define THICKENED   0x0001
#define LIGHT       0x0002
#define SKEWED      0x0004
#define UNDERLINED  0x0008
#define OUTLINED    0x0010
#define SHADOWED    0x0020



#define CLIP_OFF    0
#define CLIP_ON     1

#define COLOR_REQUESTED 0
#define COLOR_ACTUAL    1

/****** Raster definitions *********************************************/

typedef struct
{
        void            *fd_addr;
        int             fd_w;
        int             fd_h;
        int             fd_wdwidth;
        int             fd_stand;
        int             fd_nplanes;
        int             fd_r1;
        int             fd_r2;
        int             fd_r3;
} MFDB;

/***********************************************************/


/* oVDIsis call function */

extern void vdi_call(VDIPB *);



/* VDI function bindings */


extern void v_opnwk(int *, int *, int *);
extern void v_clswk(int);
extern void v_opnvwk(int *, int *, int *);
extern void v_clsvwk(int);
extern void v_clrwk(int);
extern void v_updwk(int);
extern void vs_clip(int, int, int *);
extern int vswr_mode(int, int);
extern void vs_color(int, int, int *);
extern void v_gtext(int, int, int, char *);
extern int vst_color(int, int);
extern void vst_height(int, int, int *, int *, int *, int *);
extern int vst_point(int, int, int *, int *, int *, int *);
extern int vst_effects(int, int);
extern void vst_alignment(int, int, int, int *, int *);
extern int vst_rotation(int, int);
extern void v_pline(int, int, int *);
extern int vsl_color(int, int);
extern int vsl_width(int, int);
extern int vsl_type(int, int);
extern void vsl_udsty(int, int);
extern void vsl_ends(int, int, int);
extern void v_pmarker(int, int, int *);
extern int vsm_color(int, int);
extern int vsm_height(int, int);
extern int vsm_type(int, int);
extern void v_fillarea(int, int, int *);
extern void vr_recfl(int, int *);
extern void v_contourfill(int, int, int, int);
extern int vsf_color(int, int);
extern int vsf_interior(int, int);
extern int vsf_style(int, int);
extern void vsf_udpat(int, int *, int);
extern int vsf_perimeter(int, int);
extern void v_bar(int, int *);
extern void v_arc(int, int, int, int, int, int);
extern void v_pieslice(int, int, int, int, int, int);
extern void v_circle(int, int, int, int);
extern void v_ellipse(int, int, int, int, int);
extern void v_ellarc(int, int, int, int, int, int, int);
extern void v_ellpie(int, int, int, int, int, int, int);
extern void v_rbox(int, int *);
extern void v_rfbox(int, int *);
extern void v_justified(int, int, int, char *, int, int, int);
extern void vro_cpyfm(int, int, int *, MFDB *, MFDB *);
extern void vrt_cpyfm(int, int, int *, MFDB *, MFDB *, int *);
extern void vr_trnfm(int, MFDB *, MFDB *);
extern void v_get_pixel(int, int, int, int *, int *);
extern void vsc_form(int, int *);
extern void vex_timv(int, void *, void *, int *);
extern void v_show_c(int, int);
extern void v_hide_c(int);
extern void vq_mouse(int, int *, int *, int *);
extern void vex_butv(int, void *, void *);
extern void vex_motv(int, void *, void *);
extern void vex_curv(int, void *, void *);
extern void vq_extnd(int, int, int *);
extern void vq_key_s(int, int *);
extern void vq_color(int, int, int, int *);
extern void vql_attributes(int, int *);
extern void vqm_attributes(int, int *);
extern void vqf_attributes(int, int *);
extern void vqt_attributes(int, int *);
extern void vqt_extent(int, char *, int *);
extern void vqt_width(int, char, int *, int *, int *);
extern int vqt_name(int, int, char *);
extern void vqt_fontinfo(int, int *, int *, int *, int *, int *);
extern void vqin_mode(int, int, int *);
extern void vq_chcells(int, int *, int *);
extern void v_exit_cur(int);
extern void v_enter_cur(int);
extern void v_curup(int);
extern void v_curdown(int);
extern void v_curright(int);
extern void v_curleft(int);
extern void v_curhome(int);
extern void v_eeos(int);
extern void v_eeol(int);
extern void vs_curaddress(int, int, int);
extern void v_curtext(int, char *);
extern void v_rvon(int);
extern void v_rvoff(int);
extern void vq_curaddress(int, int *, int *);
extern void v_hardcopy(int);

#endif /* _VDIBIND_H_ */



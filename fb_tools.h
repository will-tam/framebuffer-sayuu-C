/*
  Gloabl structures.
*/

#ifndef _FB_TOOLS_H
#define _FB_TOOLS_H

#include <linux/fb.h>

struct framebuffer {
  int fbfd;                         /* Framebuffer file descriptor. */
  long int screensize;              /* Figure out the size of screen in bytes. */

  char *vramfbp;                    /* Framebuffer pointer in vRAM. */
  char *dbp;                        /* Double buffer pointer. */

  unsigned short int p16;           /* Pixel in 16 bpp mode. */
  long int pxloffset;               /* Real offset of pixel in vRAM. */
  struct fb_var_screeninfo vinfo;   /* Framebuffer variable video information. */
  struct fb_fix_screeninfo finfo;   /* Framebuffer fixed video information. */
};

struct pixel {                      /* Structure for 1 pixel. */
  int x, y;                         /* Pixel (x,y). */  
  unsigned int r, g, b, a;          /* Pixel color in RGB-Alpha mode (Alpha = 0 => none). */
};

/*
  Open the fb devive file for R/W, and alloc double buffer address.
  Parameters : void.
  Return : Framebuffer structure pointer address, or NULL if somthing wrong raised.
*/
struct framebuffer *initfb();

/* 
  Close memory mapped and file descriptor.
  Parameters : void.
  Return : -1 if somthing wrong raised, everelse >= 0(see 'man 2 close' return code).
*/
int closefb(struct framebuffer *fb);

#endif
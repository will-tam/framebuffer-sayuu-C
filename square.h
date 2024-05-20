#ifndef _SQUARE_H
#define _SQUARE_H

#include "fb_tools.h"

/* 
  Create a RGB-Alpha colored square from (x0; y0) with a side length sl.
  /!\ Assume FB is in 32bpp mode. /!\
*/
void square(struct framebuffer *fbp, 
            int x0, int y0, int sl, 
            unsigned int r, unsigned int g, unsigned int b, unsigned int alpha);

#endif
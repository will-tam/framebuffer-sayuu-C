#ifndef _HLINE_H
#define _HLINE_H

#include "fb_tools.h"

/*
  Draw horizontal line from (x0; y) to (x1; y), 
  with RGB-Alpha color r, g, b, and alpha.
*/
void hline(struct framebuffer *fbp, 
           int x0, int x1, int y, 
           unsigned int r, unsigned int g, unsigned int b, unsigned int alpha);

#endif
#include <stdlib.h>
#include <stdio.h>
#include <linux/fb.h>

#include "fb_tools.h"
#include "square.h"
#include "hline.h"

/******* Variables *******/
//extern struct framebuffer fb;
//extern struct pixel p;


void square(struct framebuffer *fbp, 
            int x0, int y0, int sl, 
            unsigned int r, unsigned int g, unsigned int b, unsigned int alpha)
{
  int x1;               /* x1 = x0 + sl */
  int y1;               /* y1 = y0 + sl */

  x1 = x0 + sl;
  y1 = y0 + sl;

  for (; y0 < y1; y0++)
  {
    hline(fbp, x0, x1, y0, r, g, b, alpha);
  }

}
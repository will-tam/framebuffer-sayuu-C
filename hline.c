#include <linux/fb.h>

#include "fb_tools.h"
#include "hline.h"


void hline(struct framebuffer *fbp, 
           int x0, int x1, int y, 
           unsigned int r, unsigned int g, unsigned int b, unsigned int alpha)
{
  int d;  /* Distance between x0 and x1 */

/* Everybody inside the display. */
  if (y < 0) { y = 0; }
  if (x0 < 0) { x0 = 0; }
  if (x1 < 0) { x1 = 0; }
  if ((unsigned int)x0 > fbp->vinfo.xres) { x0 = fbp->vinfo.xres; }
  if ((unsigned int)x1 > fbp->vinfo.xres) { x1 = fbp->vinfo.xres; }
  if ((unsigned int)y > fbp->vinfo.yres) { y = fbp->vinfo.yres; }
  
  d = x1 - x0;    /* Always x1 > x0 */
  
  /* 1st offset */
  fbp->pxloffset = (x0 + fbp->vinfo.xoffset) * (fbp->vinfo.bits_per_pixel >> 3) + 
                   ((y + fbp->vinfo.yoffset) * fbp->finfo.line_length);

  for (; d > 0; d--)
  { /* Only 32bpp */
    *(fbp->dbp + fbp->pxloffset) = b;
    *(fbp->dbp + fbp->pxloffset + 1) = g;
    *(fbp->dbp + fbp->pxloffset + 2) = r;
    *(fbp->dbp + fbp->pxloffset + 3) = alpha;

    fbp->pxloffset = fbp->pxloffset + 4;
 }


}
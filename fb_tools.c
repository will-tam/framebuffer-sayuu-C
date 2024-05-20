#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                 /* Synchronous I/O multiplexing: select, FD_CLR, FD_ISSET, FD_SET, FD_ZERO. */
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>


#include "fb_tools.h"


/******* Variables *******/
struct framebuffer fb;
//struct pixel p;

//int i;                            /* Some index. */
//int rc;                           /* Return code to simplify tuto. */


struct framebuffer *initfb()
{
  int rc;


  /* Open the fb devive file for R/W. */
  fb.fbfd = open("/dev/fb0", O_RDWR);    /* Expect the first FB is allowed. */

  if (fb.fbfd == -1)
  {
    perror("Fail to open /dev/fb0 ");
    return NULL;
  }
  printf("/dev/fb0 opened.\n");

  /* Get fixed informations about screen. */
  rc = ioctl(fb.fbfd, FBIOGET_FSCREENINFO, &fb.finfo);
  printf("\nioctl(fb.fbfd, FBIOGET_FSCREENINFO, &fb.finfo) rc = %d\n", rc);
  if (rc)
  {
    close(fb.fbfd);
    perror("Fail to read screen fixed informations ");
    return NULL;
  }

  /* Get variable informations about screen. */
  rc = ioctl(fb.fbfd, FBIOGET_VSCREENINFO, &fb.vinfo);
  printf("\nioctl(fb.fbfd, FBIOGET_VSCREENINFO, &fb.vinfo) rc = %d\n", rc);
  if (rc)
  {
    close(fb.fbfd);
    perror("Fail to read screen variable informations ");
    return NULL;
  }

  printf("\n");
  /* Get variable informations VLB. */

  fb.screensize = fb.vinfo.xres_virtual * fb.vinfo.yres * fb.vinfo.bits_per_pixel >> 3;

  /* Map /dev/fb0 to vRAM. */
  fb.vramfbp = (char *) mmap(0, fb.screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb.fbfd, 0);
  if ((long) fb.vramfbp == -1)
  {
    perror("/dev/fb0 can't be mapped ");
    rc = close(fb.fbfd);
    if (rc == -1)
    {
      perror("Coundn't close /dev/fb0 ");
    }
    else
    {
      printf("/dev/fb0 closed\n");
    }
    perror("Fail to map /dev/fb0 to vRAM ");
    return NULL;
  }
  printf("/dev/fb0 is mapped to vRAM\n\n");

  fb.dbp = calloc(fb.screensize, sizeof(char));
  if (fb.dbp == NULL)
  {
    perror("Double buffer allocation error ");
  
    munmap(fb.vramfbp, fb.screensize);

    rc = close(fb.fbfd);
    if (rc == -1)
    {
      perror("Coundn't close /dev/fb0 ");
    }
    else
    {
      printf("/dev/fb0 closed\n");
    }
    perror("Fail to map /dev/fb0 to vRAM ");
    return NULL;
  }
  
  return &fb;
}

int closefb(struct framebuffer *fb)
{
  free(fb->dbp);
  munmap(fb->vramfbp, fb->screensize);

  return close(fb->fbfd);
}

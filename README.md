# Framebuffer right and left moving squre (C version)

Just a square moving from right to left, and right, and left, ... to test frambuffer library.

**/!\ Assume FB is in 32bpp mode. /!\\**

## The best way to test :
- Create a Linux virtual machine (VM) with an X server.
- In console mode:
  - Check and configure network between VM and your physical machine (PM).
  - install, configure and run the ssh server.
  - Log off or not, but the VM still active.
- Open a terminal on your PM.
  - Open a ssh connection with the VM.
  - Install and configure the C development kit (gcc + make + lib in debug/dev).
  - Install git.
  - Clone this repository.
  - Go to the newly created directory.
  - Just type ```make```.
  - If all is ok, the VM console shows you nice arts, while the ssh terminal shows some information.

Of course, you can try directly in your PM (in TTY1 for example - CTRL-ALT-F1 if you use X interface). 
**BUT if something wrong, prepare to reboot your PM**.

## Great thanks to
- **Framebuffer** :
  - [https://github.com/roddehugo/linuxfb?tab=readme-ov-file](https://github.com/roddehugo/linuxfb?tab=readme-ov-file)
  - [https://wiki.osdev.org/Drawing_In_a_Linear_Framebuffer](https://wiki.osdev.org/Drawing_In_a_Linear_Framebuffer)
  - [https://github.com/DirectFB/directfb/tree/master/systems/fbdev](https://github.com/DirectFB/directfb/tree/master/systems/fbdev)

- **Key events** :
  - [https://www.flipcode.com/archives/_kbhit_for_Linux.shtml](https://www.flipcode.com/archives/_kbhit_for_Linux.shtml)


# ENJOY

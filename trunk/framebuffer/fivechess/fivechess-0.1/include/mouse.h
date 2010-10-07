#ifndef __mouse_h__
#define __mouse_h__

#define C_WIDTH  10  
#define C_HEIGHT 17
#define T___     0XFFFFFFFF
#define BORD     0x0
#define X___     0xFFFF

/*
 *鼠标数组
 */

static unsigned long cursor_pixel[C_WIDTH * C_HEIGHT] = {
  BORD, T___, T___, T___, T___, T___, T___, T___, T___, T___,
  BORD, BORD, T___, T___, T___, T___, T___, T___, T___, T___,
  BORD, X___, BORD, T___, T___, T___, T___, T___, T___, T___,
  BORD, X___, X___, BORD, T___, T___, T___, T___, T___, T___,
  BORD, X___, X___, X___, BORD, T___, T___, T___, T___, T___,
  BORD, X___, X___, X___, X___, BORD, T___, T___, T___, T___,
  BORD, X___, X___, X___, X___, X___, BORD, T___, T___, T___,
  BORD, X___, X___, X___, X___, X___, X___, BORD, T___, T___,
  BORD, X___, X___, X___, X___, X___, X___, X___, BORD, T___,
  BORD, X___, X___, X___, X___, X___, X___, X___, X___, BORD,
  BORD, X___, X___, X___, X___, X___, BORD, BORD, BORD, BORD,
  BORD, X___, X___, BORD, X___, X___, BORD, T___, T___, T___,
  BORD, X___, BORD, T___, BORD, X___, X___, BORD, T___, T___,
  BORD, BORD, T___, T___, BORD, X___, X___, BORD, T___, T___,
  T___, T___, T___, T___, T___, BORD, X___, X___, BORD, T___,
  T___, T___, T___, T___, T___, BORD, X___, X___, BORD, T___,
  T___, T___, T___, T___, T___, T___, BORD, BORD, T___, T___
};

#endif

#ifndef CREACT_H
#define CREACT_H

//Include
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#ifdef __MINGW32__
#include <windows.h>
#endif

//Types
typedef enum {
  CR_BLACK,
  CR_RED,
  CR_GREEN,
  CR_YELLOW,
  CR_BLUE,
  CR_MAGENTA,
  CR_CYAN,
  CR_LIGHTGRAY,
  CR_DARKGRAY,
  CR_LIGHTRED,
  CR_LIGHTGREEN,
  CR_LIGHTYELLOW,
  CR_LIGHTBLUE,
  CR_LIGHTMAGENTA,
  CR_LIGHTCYAN,
  CR_WHITE,
} cr_colors_t;

//Functions
void cr_resetColors();
void cr_bgColor(cr_colors_t color);
void cr_textColor(cr_colors_t color);
void cr_setColors(cr_colors_t bgColor, cr_colors_t textColor);

#endif /*CREACT_H*/
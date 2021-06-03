//Includes
#include "../include/creact.h"

//Constants

//Variables
#ifdef __MINGW32__
unsigned char _enableColors = 0;
#else
unsigned char _enableColors = 1;
#endif
unsigned char _textColor = 30;
unsigned char _bgColor = 37;

//Functions
void _cr_windowsColorFix(){
  if(_enableColors == 0){
    #ifdef __MINGW32__
      #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      if (handle != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        if (GetConsoleMode(handle, &mode)) {
          mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
          SetConsoleMode(handle, mode);
        }
      }
      _enableColors = 1;
    #endif
  }
}
void _cr_updateColor(){
  _cr_windowsColorFix();
  printf("\e[0;%d;%dm", _bgColor, _textColor);
}

void cr_resetColors(){
  _cr_windowsColorFix();
  printf("\e[0m");
}

void cr_bgColor(cr_colors_t color){
  _bgColor = (color <= 7) ? color + 40 : color - 8 + 100;
  _cr_updateColor();
}

void cr_textColor(cr_colors_t color){
  _textColor = (color <= 7) ? color + 30 : color - 8 + 90;
  _cr_updateColor();
}

void cr_setColors(cr_colors_t bgColor, cr_colors_t textColor){
  _bgColor = (bgColor <= 7) ? bgColor + 40 : bgColor - 8 + 100;
  _textColor = (textColor <= 7) ? textColor + 30 : textColor - 8 + 90;
  _cr_updateColor();
}
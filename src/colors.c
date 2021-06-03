//Includes
#include "../include/creact.h"
#include "../include/fix.h"

//Constants

//Variables
unsigned char _textColor = 30;
unsigned char _bgColor = 37;

//Functions
void _cr_updateColor(){
  cr_fixCommands();
  printf("\e[0;%d;%dm", _bgColor, _textColor);
}

void cr_resetColors(){
  cr_fixCommands();
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
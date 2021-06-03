//Includes
#include "../include/creact.h"
#include "../include/fix.h"

//Functions
void cr_moveCursorUp(int lines){
  cr_fixCommands();
  printf("\e[%dA", lines);
}

void cr_moveCursorDown(int lines){
  cr_fixCommands();
  printf("\e[%dB", lines);
}

void cr_moveCursorRight(int collumns){
  cr_fixCommands();
  printf("\e[%dC", collumns);
}

void cr_moveCursorLeft(int collumns){
  cr_fixCommands();
  printf("\e[%dD", collumns);
}

void cr_moveCursorXY(int x, int y){
  cr_fixCommands();
  printf("\e[%d;%dH", y, x);
}

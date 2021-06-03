//Includes
#include "../include/creact.h"
#include "../include/fix.h"

//Functions
void cr_clearScreen(){
  cr_fixCommands();
  printf("\e[2J");
}
//Includes
#include "../include/creact.h"
#include "../include/fix.h"

//Constants

//Variables
#ifdef __MINGW32__
unsigned char _fixed = 0;
#else
unsigned char _fixed = 1;
#endif

//Functions
void cr_fixCommands(){
  if(_fixed == 0){
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
      _fixed = 1;
    #endif
  }
}

#ifndef start_h
#define start_h
#include <iostream>

class CWindow
{
private:
  SDL_Window* gWindow;
  bool gIR;
public:
  CWindow
  {
    gWindow = SDL_CreateWindow(
    "InfinityDungeon.exe",
    100,
    100,
    1024,
    768,
    0
    );
    if(!gWindow){SDL_Log("Failed to create window: %s", SDL_GetError());}
  }
}
#endif

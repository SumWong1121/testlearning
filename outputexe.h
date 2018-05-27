#ifndef start_h
#define start_h
#include <iostream>

mWindow = SDL_CreateWindow(
"InfinityDungeon.exe",
100,
100,
1024,
768,
0
);

if(!mWindow){SDL_Log("Failed to create window: %s", SDL_GetError());}

#endif

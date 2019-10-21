#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "SdlTexture.h"

int main(int argc, char** argv){
  try {
    SdlWindow window(700, 700);
    window.fill();
    // Usar factory
    SdlTexture im("Finish.png", window);
    Area srcArea(0, 0, 1430, 445);
    Area destArea(0, 0, 300, 300);
    //im.render(srcArea, destArea);
    im.render(srcArea,destArea, (double) 90, SDL_FLIP_NONE);
    window.render();
    SDL_Delay(3000);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
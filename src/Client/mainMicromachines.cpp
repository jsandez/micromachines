#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Pista.h"

//The dimensions of the level
const int LEVEL_WIDTH = 1920;
const int LEVEL_HEIGHT = 1080;

int main(int argc, char **argv) {
  try {
    SdlWindow window(LEVEL_WIDTH, LEVEL_HEIGHT);
    window.fill();
    Pista pista(270, 270);
    pista.dibujar(window);
    window.render();
    SDL_Delay(3000);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
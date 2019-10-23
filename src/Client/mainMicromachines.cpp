#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "SdlWindow.h"
#include "Pista.h"
#include "Car.h"

//The dimensions of the level
const int LEVEL_WIDTH = 1920;
const int LEVEL_HEIGHT = 1080;

int main(int argc, char **argv) {
  try {
    SdlWindow window(LEVEL_WIDTH, LEVEL_HEIGHT);
    window.fill();
    Pista pista(295, 295);
    pista.dibujar(window);
    Car car(100,100);
    car.dibujar(window);
    window.render();
    SDL_Delay(3000);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
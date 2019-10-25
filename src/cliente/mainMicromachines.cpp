#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/Pista.h"
#include "includes/cliente/Car.h"

const int LEVEL_WIDTH = 1920;
const int LEVEL_HEIGHT = 1080;

int main(int argc, char **argv) {
  try {
    SDL_Rect camera = {0, 0, 640, 480};
    SdlWindow window(LEVEL_WIDTH, LEVEL_HEIGHT);
    SdlTexture im_corner("assets/Road_01_Tile_01.png", window);
    SdlTexture im_road("assets/Road_01_Tile_03.png", window);
    SdlTexture im_car("assets/pitstop_car_1.png", window);
    window.fill();
    Pista pista(295, 295, im_road, im_corner);
    Car car(100, 100, im_car);
    bool quit = false;
    int x = 0;
    int y = 0;
    while (!quit) {
      //empezar contador
      SDL_Event event;
      window.fill();
      pista.dibujar(window);
      camera.x = car.getX() - 640 / 2;
      camera.y = car.getY() - 480 / 2;
      if (camera.x < 0) {
        camera.x = 0;
      }
      if (camera.y < 0) {
        camera.y = 0;
      }
      if (camera.x > camera.w) {
        camera.x = camera.w;
      }
      if (camera.y > camera.h) {
        camera.y = camera.h;
      }
      car.dibujar(x - camera.x, y - camera.y);
      // terminar contador
      while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
          case SDL_KEYDOWN: {
            SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &) event;
            switch (keyEvent.keysym.sym) {
              case SDLK_LEFT:x -= 10;
                break;
              case SDLK_RIGHT:x += 10;
                break;
              case SDLK_UP:y -= 10;
                break;
              case SDLK_DOWN:y += 10;
                break;
            }
          } // Fin KEY_DOWN
            break;
          case SDL_MOUSEMOTION:std::cout << "Oh! Mouse" << std::endl;
            break;
          case SDL_QUIT:std::cout << "Quit :(" << std::endl;
            quit = true;
            break;
        }
      }
      window.render();
      // wait diferencia porcentual
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
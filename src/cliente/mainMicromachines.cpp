#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "includes/cliente/VistaPasto.h"
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/Pista.h"
#include "includes/cliente/VistaAuto.h"

const int LEVEL_WIDTH = 4096;
const int LEVEL_HEIGHT = 2160;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char **argv) {
  try {
    SdlWindow window(SCREEN_WIDTH, SCREEN_HEIGHT);
    SdlTexture im_corner("assets/Road_01_Tile_01.png", window);
    SdlTexture im_grass("assets/background_grass.png", window);
    SdlTexture im_road("assets/Road_01_Tile_03.png", window);
    SdlTexture im_car("assets/pitstop_car_1.png", window);
    window.fill();
    Pista pista(295, 295, im_road, im_corner, im_grass);
    VistaPasto grass(LEVEL_WIDTH, LEVEL_HEIGHT, 0, im_grass);
    VistaAuto car(100, 100, -90, im_car);
    bool quit = false;
    int x = 0;
    int y = 0;
    int xCamara = 0;
    int yCamara = 0;
    while (!quit) {
      //empezar contador
      SDL_Event event;
      window.fill();
      //pista.dibujar(window);
      xCamara = (car.getX() + 100 / 2) - SCREEN_WIDTH / 2;
      yCamara = (car.getY() + 100 / 2) - SCREEN_HEIGHT / 2;
      if (xCamara < 0) {
        xCamara = 0;
      }
      if (yCamara < 0) {
        yCamara = 0;
      }
      if (xCamara > LEVEL_WIDTH - SCREEN_WIDTH) {
        xCamara = LEVEL_WIDTH - SCREEN_WIDTH;
      }
      if (yCamara > LEVEL_HEIGHT - SCREEN_HEIGHT) {
        yCamara = LEVEL_HEIGHT - SCREEN_HEIGHT;
      }
      std::cout << "xCamara " << xCamara << std::endl;
      std::cout << "yCamara " << yCamara << std::endl;
      grass.dibujar(xCamara, yCamara);
      car.dibujar(car.getX() - xCamara, car.getY() - yCamara);
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
        car.mover(x, y);
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
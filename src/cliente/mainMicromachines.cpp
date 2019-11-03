#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VentanaPartida.h"

// TODO: HAY QUE HACER LOS PIXELES REELATIVOS A LA RESOLUCION
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char **argv) {
  try {
    SdlWindow window(SCREEN_WIDTH, SCREEN_HEIGHT);
    VentanaPartida ventana_partida(window);
    CreadorTexturas creador_texturas(window);
    ventana_partida.crearPista();
    std::shared_ptr<VistaObjeto> car = creador_texturas.crear(105);
    ventana_partida.addAuto(car);
    //window.fill();
    //ventana_partida.dibujar();
    //SDL_Delay(3000);
    bool running = true;
    int x = 0;
    int y = 0;
    while (running) {
      //empezar contador
      SDL_Event event;
      car.get()->mover(x, y, 0);
      window.fill();
      while (SDL_PollEvent(&event) != 0) {
        x = 0;
        y = 0;
        switch (event.type) {
          case SDL_KEYDOWN: {
            SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &) event;
            switch (keyEvent.keysym.sym) {
              case SDLK_LEFT:x = -1;
                break;
              case SDLK_RIGHT:x = 1;
                break;
              case SDLK_UP:y = -1;
                break;
              case SDLK_DOWN:y = 1;
                break;
            }
          } // Fin KEY_DOWN
            break;
          case SDL_MOUSEMOTION:std::cout << "Oh! Mouse" << std::endl;
            break;
          case SDL_QUIT:std::cout << "Quit :(" << std::endl;
            running = false;
            break;
        }
        //SDL_Delay(300);
      }
      ventana_partida.dibujar();
      // wait diferencia porcentual
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
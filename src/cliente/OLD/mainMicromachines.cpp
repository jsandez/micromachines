#include <SDL2/SDL.h>
#include <iostream>
#include <exception>
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VentanaPartida.h"

// TODO: HAY QUE HACER LOS PIXELES REELATIVOS A LA RESOLUCION
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main(int argc, char **argv) {
  try {
    SdlWindow window(SCREEN_WIDTH, SCREEN_HEIGHT);
    VentanaPartida ventana_partida(window);
    CreadorTexturas creador_texturas(window);
    std::shared_ptr<VistaObjeto> car = creador_texturas.crear(105);
    std::shared_ptr<VistaObjeto> car_2 = creador_texturas.crear(105);
    std::shared_ptr<VistaObjeto> car_3 = creador_texturas.crear(105);
    ventana_partida.addAutoPrincipal(car, 0);
    ventana_partida.addObjeto(car_2, 1);
    ventana_partida.addObjeto(car_3, 2);
    car.get()->mover(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
    car_2.get()->mover(100, 100, 0);
    car_3.get()->mover(100, 100, 0);
    bool running = true;
    int x = 0;
    int y = 0;
    // TODO: ESTO TIENE QUE SER UN THREAD QUE ESPERA EVENTOS Y LOS EJECUTA
    while (running) {
      //empezar contador
      SDL_Event event;
      car.get()->mover(x, y, 0);
      car_2.get()->mover(1, 0, 0);
      car_3.get()->mover(0, 1, 0);
      window.fill();
      while (SDL_PollEvent(&event) != 0) {
        x = 0;
        y = 0;
        switch (event.type) {
          // TODO: REVISAR, CUANDO DOBLA; COMO CONTROLAMOS LA DIAGONAL??
          // TODO: PROPUESTA, ESPACIO PARA ACELERAR??
          case SDL_KEYDOWN: {
            SDL_KeyboardEvent &keyEvent = (SDL_KeyboardEvent &) event;
            switch (keyEvent.keysym.sym) {
              case SDLK_LEFT:x = -5;
                break;
              case SDLK_RIGHT:x = 5;
                break;
              case SDLK_UP:y = -5;
                break;
              case SDLK_DOWN:y = 5;
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
      }
      // TODO: ACA VA EL NUMERO DE ITERACION
      ventana_partida.dibujar();
      // wait diferencia porcentual
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
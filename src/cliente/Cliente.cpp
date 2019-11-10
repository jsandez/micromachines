#include "includes/cliente/Cliente.h"

#include <iostream>
#include <SDL2/SDL.h>

Cliente::Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana, const std::string& host, const std::string& puerto) :
    ventana_(anchoVentana, altoVentana, pantallaCompleta, tituloVentana),
    renderizador_(ventana_),
    dibujador_(ventana_, renderizador_),
    socket_(host, puerto),
    recibidor_(socket_, dibujador_.eventosEntrantes(), 0) {
}

Cliente::~Cliente() {
    dibujador_.join();
    recibidor_.join();
}

void Cliente::correr() {
    try {
        socket_.conectar();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }   

    recibidor_.iniciar();
    dibujador_.iniciar();

    SDL_Event evento;
    while (SDL_WaitEvent(&evento) != 0) {
        switch (evento.type) {
        case SDL_KEYDOWN:
            manejarKeyDown();

            
         {
            SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent &)evento;
            switch (keyEvent.keysym.sym) {
                            case SDLK_LEFT:
                                x -= 10;
                                break;
                            case SDLK_RIGHT:
                                x += 10;
                                break;
                            case SDLK_UP:
                                y -= 10;
                                break;
                            case SDLK_DOWN:
                                y += 10;
                                break;
                            }
                    } // Fin KEY_DOWN
        }
    }
    while (SDL_WaitEvent(&evento) != 0) {
        x = 0;
        y = 0;
        switch (event.type) {
          case SDL_KEYDOWN: {
            
            if (event.key.repeat == 0) {
              switch (keyEvent.keysym.sym) {
                case SDLK_SPACE: {
                  std::shared_ptr<Evento> eventoAcelerar = std::make_shared<EventoAcelerar>();
                  cola_bloqueante.put(eventoAcelerar);
                  break;
                }
              }
            }
          }
          case SDL_MOUSEMOTION:std::cout << "Oh! Mouse" << std::endl;
            break;
          case SDL_QUIT:std::cout << "Quit :(" << std::endl;
            running = false;
            break;
        }
      }








    char c;
    while ((c = std::cin.get()) != 'q') {
        // pass
    }
    cerrar();
}

void Cliente::cerrar() {
    dibujador_.detener();
    recibidor_.detener();
    socket_.cerrarLectoEscritura();
}


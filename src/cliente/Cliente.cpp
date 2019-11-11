#include "includes/cliente/Cliente.h"

#include <iostream>

#include "includes/common/eventos/EventoAcelerar.h"

Cliente::Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana, const std::string& host, const std::string& puerto) :
    ventana_(anchoVentana, altoVentana, pantallaCompleta, tituloVentana),
    renderizador_(ventana_),
    dibujador_(ventana_, renderizador_),
    socket_(host, puerto),
    recibidor_(socket_, dibujador_.eventosEntrantes(), 0),
    enviador_(socket_, eventosAEnviar_) {
}

Cliente::~Cliente() {
    dibujador_.join();
    enviador_.join();
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
    enviador_.iniciar();
    dibujador_.iniciar();

    bool seguirCorriendo = true;
    SDL_Event evento;
    while (SDL_WaitEvent(&evento) != 0 && seguirCorriendo) {
        switch (evento.type) {
            case SDL_KEYDOWN:
                manejarKeyDown(evento);
                break;
            case SDL_KEYUP:
                manejarKeyUp(evento);
                break;
            case SDL_QUIT:
                seguirCorriendo = false;
                break;
            default:
                break;
        }
    }
}

void Cliente::cerrar() {
    dibujador_.detener();
    eventosAEnviar_.detener();
    enviador_.detener();
    recibidor_.detener();
    socket_.cerrarLectoEscritura();
}

void Cliente::manejarKeyDown(SDL_Event& eventoSDL) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&)eventoSDL;
    if (eventoSDL.key.repeat != 0) {
      return;
    }
    std::shared_ptr<Evento> evento;
    switch (keyEvent.keysym.sym) {
        case SDLK_SPACE:
            evento = std::make_shared<EventoAcelerar>();
            eventosAEnviar_.put(evento);
            break;
        default:
            break;
        
    }
}

void Cliente::manejarKeyUp(SDL_Event& evento) {

}

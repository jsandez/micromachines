#include "includes/cliente/HiloDibujador.h"

#include "includes/cliente/GUI/escenas/EscenaMenu.h"
#include "includes/cliente/GUI/Renderizador.h"

#include <SDL2/SDL.h>

HiloDibujador::HiloDibujador(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana) :
    ventana_(anchoVentana, altoVentana, pantallaCompleta, tituloVentana),
    renderizador_(ventana_) {

}

void HiloDibujador::correr() {
    EscenaMenu e;    
    while(seguirCorriendo_) {
        renderizador_.dibujar(1, e);
        SDL_Delay(100);
    }
}

void HiloDibujador::detener() {
    seguirCorriendo_ = false;
}

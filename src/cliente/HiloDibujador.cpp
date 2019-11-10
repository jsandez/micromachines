#include "includes/cliente/HiloDibujador.h"

#include "includes/cliente/GUI/escenas/EscenaMenu.h"

#include <SDL2/SDL.h>

HiloDibujador::HiloDibujador(Ventana& ventana, Renderizador& renderizador) :
    ventana_(ventana),
    renderizador_(renderizador) {
}

void HiloDibujador::correr() {
    EscenaMenu e(renderizador_);    
    uint32_t iteracion = 0;
    while(seguirCorriendo_) {
        renderizador_.dibujar(iteracion, e);
        iteracion+=1;
        SDL_Delay(100);
    }
}

void HiloDibujador::detener() {
    seguirCorriendo_ = false;
}

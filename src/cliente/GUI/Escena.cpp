#include "includes/cliente/GUI/Escena.h"

#include <SDL2/SDL_render.h>

#include "includes/cliente/GUI/Textura.h"

Escena::Escena(Ventana& ventana, Renderizador& renderizador) :
    ventana_(ventana),
    renderizador_(renderizador) {
}

void Escena::dibujar(uint32_t numeroIteracion) {
    Textura textura("assets/background_menu.jpg", renderizador_);
    renderizador_.dibujarAbsoluto(textura, 0, 0);
}

void Escena::presentar() {
    SDL_RenderPresent(renderizador_.getSDL());
}

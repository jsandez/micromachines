#include "includes/cliente/Renderizador.h"

#include <SDL2/SDL_render.h>

#include "includes/cliente/Ventana.h"

Renderizador::Renderizador(Ventana& ventana) :
    ventana_(ventana) {
    renderizadorSDL_ = SDL_CreateRenderer(ventana.getSDL(), SDL_PRIMER_DISPONIBLE, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}

Renderizador::~Renderizador() {
    SDL_DestroyRenderer(renderizadorSDL_);
}

#include "includes/cliente/GUI/Renderizador.h"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Textura.h"

Renderizador::Renderizador(Ventana& ventana) :
    ventana_(ventana) {
    renderizadorSDL_ = SDL_CreateRenderer(ventana.getSDL(), SDL_PRIMER_DISPONIBLE, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}

Renderizador::~Renderizador() {
    SDL_DestroyRenderer(renderizadorSDL_);
}

/*void Renderizador::dibujarAbsoluto(Textura& textura, int xDesde, int yDesde) {
    SDL_Rect sdlSrc = {
            0, 0,
            1280, 720
    };
    SDL_Rect sdlDest = sdlSrc;

    SDL_RenderCopy(renderizadorSDL_, textura.getSDL(), &sdlSrc, &sdlDest);
}*/

SDL_Renderer* Renderizador::getSDL() {
    return renderizadorSDL_;
}

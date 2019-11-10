#include "includes/cliente/GUI/Renderizador.h"

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/escenas/Escena.h"

Renderizador::Renderizador(Ventana& ventana) :
    ventana_(ventana) {
    renderizadorSDL_ = SDL_CreateRenderer(ventana.getSDL(), SDL_PRIMER_DISPONIBLE, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}

Renderizador::~Renderizador() {
    SDL_DestroyRenderer(renderizadorSDL_);
}

void Renderizador::clear() {
    SDL_SetRenderDrawColor(renderizadorSDL_, 0x33,0x33,0x33,0xFF);
    SDL_RenderClear(renderizadorSDL_);
}

void Renderizador::setDestino(Textura& textura) {
    SDL_SetRenderTarget(renderizadorSDL_, textura.getSDL());
    clear();
}

void Renderizador::resetDestino() {
    SDL_SetRenderTarget(renderizadorSDL_, NULL);
}

void Renderizador::dibujar(Textura& textura, Area& area) {
    SDL_Rect SDLDestino = {
        (int)area.x(),
        (int)area.y(),
        (int)area.ancho(),
        (int)area.alto()
        };
    SDL_RenderCopy(renderizadorSDL_, textura.getSDL(), NULL, &SDLDestino);
}

void Renderizador::dibujar(uint32_t numeroIteracion, Escena& escena) {
    Textura textura = escena.dibujate(numeroIteracion, *this, ventana_.dimensiones());
    SDL_Rect SDLDestino = {
        0,
        0,
        (int)ventana_.ancho(),
        (int)ventana_.alto()};
    SDL_RenderCopy(renderizadorSDL_, textura.getSDL(), NULL, &SDLDestino);
    SDL_RenderPresent(renderizadorSDL_);
}

SDL_Renderer* Renderizador::getSDL() {
    return renderizadorSDL_;
}

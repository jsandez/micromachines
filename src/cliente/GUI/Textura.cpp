#include "includes/cliente/GUI/Textura.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/excepciones/SDLException.h"

Textura::Textura(const std::string& rutaArchivo, Renderizador& renderizador) :
    renderizador_(renderizador) {
    
    texturaSDL_ = IMG_LoadTexture(renderizador_.getSDL(), rutaArchivo.c_str());
    if (!texturaSDL_) {
        throw SDLException("Error al cargar la textura", SDL_GetError());
    }
}

Textura::~Textura() {
    SDL_DestroyTexture(texturaSDL_);
}

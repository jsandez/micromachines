#include "includes/cliente/GUI/Textura.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/excepciones/SDLException.h"

Textura::Textura(const std::string& rutaArchivo, std::shared_ptr<Renderizador> renderizador) :
    renderizador_(renderizador) {
    
    texturaSDL_ = IMG_LoadTexture(renderizador_->getSDL(), rutaArchivo.c_str());
    if (!texturaSDL_) {
        throw SDLException("Error al cargar la textura", SDL_GetError());
    }
}

Textura::Textura(Textura&& otraTextura) {
    this->texturaSDL_ = otraTextura.texturaSDL_;
    otraTextura.texturaSDL_ = nullptr;
    
    this->renderizador_ = otraTextura.renderizador_;
    otraTextura.renderizador_.reset();
}

Textura& Textura::operator=(Textura&& otraTextura) {
    this->texturaSDL_ = otraTextura.texturaSDL_;
    otraTextura.texturaSDL_ = nullptr;

    this->renderizador_ = otraTextura.renderizador_;
    otraTextura.renderizador_.reset();
    return *this;
}

Textura::~Textura() {
    if (texturaSDL_ != nullptr) {
        SDL_DestroyTexture(texturaSDL_);
    }    
}

SDL_Texture* Textura::getSDL() {
    return texturaSDL_;
}

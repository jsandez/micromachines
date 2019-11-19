#include "includes/cliente/GUI/Texto.h"
#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/excepciones/SDLException.h"
#include "includes/cliente/GUI/Renderizador.h"

SDL_Texture *Texto::createFromText(const std::string texto, Renderizador &renderizador) {
  SDL_Color blanco = {255, 255, 255};
  SDL_Surface *surface = TTF_RenderText_Blended(this->font, texto.c_str(), blanco);
  if (!surface)
    throw SDLException("Error con TTF_RenderText_Blended:", SDL_GetError());
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderizador.getSDL(), surface);
  if (!texture) {
    throw SDLException("Error al cargar la textura", SDL_GetError());
  }
  SDL_FreeSurface(surface);
  return texture;
}

Texto::Texto(const std::string texto, const int size, Renderizador &renderizador) {
  if (TTF_Init() == -1)
    throw SDLException("Error al iniciar TTF:", SDL_GetError());
  this->font = TTF_OpenFont(CONFIG_CLIENTE.fuente().c_str(), size);
  if (font == NULL)
    throw SDLException("Error al cargar font:", SDL_GetError());
  this->texturaSDL_ = createFromText(texto, renderizador);
}

SDL_Texture *Texto::getSDL() {
  return texturaSDL_;
}

Texto::Texto(Texto &&other) {
  this->texturaSDL_ = other.texturaSDL_;
  this->font = other.font;
  other.texturaSDL_ = nullptr;
  other.font = nullptr;
}

Texto &Texto::operator=(Texto &&other) {
  if (this == &other) {
    return *this;
  }
  if (this->texturaSDL_) {
    SDL_DestroyTexture(texturaSDL_);
  }
  if (this->font) {
    TTF_CloseFont(this->font);
    TTF_Quit();
  }
  this->texturaSDL_ = other.texturaSDL_;
  this->font = other.font;

  other.texturaSDL_ = nullptr;
  other.font = nullptr;
  return *this;
}

Texto::~Texto() {
  if (texturaSDL_ != nullptr) {
    SDL_DestroyTexture(texturaSDL_);
  }
  if (font != nullptr) {
    TTF_CloseFont(this->font);
    TTF_Quit();
  }
}
#ifndef _TEXTO_H_
#define _TEXTO_H_

#include "includes/cliente/GUI/Textura.h"
#include "includes/cliente/GUI/Renderizador.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Texto {
 private:
  TTF_Font *font;
  SDL_Texture *texturaSDL_;
  int textWidth;
  int textHeight;
  SDL_Texture *createFromText(const std::string texto, Renderizador &renderizador);

 public:
  Texto(const std::string texto, const int size, Renderizador &renderizador);
  SDL_Texture* getSDL();
};
#endif

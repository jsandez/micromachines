#ifndef _TEXTO_H_
#define _TEXTO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "string"

class Renderizador;

class Texto {
 private:

  TTF_Font *font;
  SDL_Texture *texturaSDL_;

  SDL_Texture *createFromText(const std::string texto, Renderizador &renderizador);
  Texto(const Texto &) = delete;
  Texto &operator=(const Texto &) = delete;

 public:
  Texto(const std::string texto, const int size, Renderizador &renderizador);
  SDL_Texture *getSDL();

  Texto(Texto &&other);
  Texto &operator=(Texto &&other);

  ~Texto();
};
#endif

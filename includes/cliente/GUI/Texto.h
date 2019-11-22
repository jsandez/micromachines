#ifndef _TEXTO_H_
#define _TEXTO_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "string"

#define UUID_TEXTO_BLANCO 1
#define UUID_TEXTO_NEGRO 2
#define UUID_TEXTO_ROJO 3

class Renderizador;

class Texto {
 private:

  TTF_Font *font;
  SDL_Texture *texturaSDL_;

  SDL_Color getColor(int uuidColor);
  SDL_Texture *createFromText(const std::string texto, Renderizador &renderizador,int uuidColor);
  Texto(const Texto &) = delete;
  Texto &operator=(const Texto &) = delete;

 public:
  Texto(const std::string texto, const int size, Renderizador &renderizador,int uuidColor);
  SDL_Texture *getSDL();

  Texto(Texto &&other);
  Texto &operator=(Texto &&other);

  ~Texto();
};
#endif

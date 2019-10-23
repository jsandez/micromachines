#ifndef _PISTA_H_
#define _PISTA_H_
#include "SdlTexture.h"
#include "Area.h"

class Pista {
 private:
  int width;
  int height;
 public:
  Pista(int width, int height);
  void dibujar(SdlWindow &sdl_window);
};

#endif

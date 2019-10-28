#ifndef _PISTA_H_
#define _PISTA_H_
#include "SdlTexture.h"
#include "Area.h"

class Pista {
 private:
  int width;
  int height;
  SdlTexture road;
  SdlTexture corner;
  SdlTexture grass;
 public:
  Pista(int width, int height, SdlTexture &road, SdlTexture &corner, SdlTexture &grass);
  void dibujar(SdlWindow &sdl_window);
};

#endif

#ifndef _VISTAOBJETO_H_
#define _VISTAOBJETO_H_
#include "SdlTexture.h"

class VistaObjeto {
 protected:
  int x, y, width, height;
  SdlTexture textura;
 public:
  VistaObjeto(int width, int height, SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y) = 0;
  virtual void mover(int x, int y) = 0;
  virtual void rotar(int rotacion) = 0;
  int getX();
  int getY();
};
#endif

#ifndef _VISTAOBJETO_H_
#define _VISTAOBJETO_H_
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "includes/cliente/Area.h"

class VistaObjeto {
 protected:
  int x, y, width, height;
  SdlTexture textura;
 public:
  VistaObjeto(SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y, int angulo) = 0;
  /*virtual void mover(int posX, int posY);
  virtual void rotar(int rotacion);*/
  int getX();
  int getY();
};
#endif

#ifndef _VISTAAUTO_H_
#define _VISTAAUTO_H_
#include "includes/cliente/VistaObjetoMovil.h"

class VistaAuto : public VistaObjetoMovil {
 public:
  VistaAuto(int width, int height, int angulo, SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y) override;
};

#endif

#ifndef _VISTAAUTO_H_
#define _VISTAAUTO_H_
#include "includes/cliente/VistaObjetoDinamico.h"

class VistaAuto : public VistaObjetoDinamico {
 public:
  VistaAuto(SdlTexture &sdl_texture, int x, int y, int angulo);
  virtual void dibujar(int x, int y, int angulo) override;
};

#endif

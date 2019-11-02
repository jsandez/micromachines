#ifndef _VISTAAUTO_H_
#define _VISTAAUTO_H_
#include "includes/cliente/VistaObjeto.h"

class VistaAuto : public VistaObjeto {
 public:
  VistaAuto(SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y,int angulo) override;
};

#endif

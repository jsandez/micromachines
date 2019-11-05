#ifndef _VISTATIERRA_H_
#define _VISTATIERRA_H_
#include "includes/cliente/VistaObjeto.h"

class VistaTierra : public VistaObjeto {
 public:
  VistaTierra(SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y, int angulo, int screenX, int screenY) override;
};

#endif

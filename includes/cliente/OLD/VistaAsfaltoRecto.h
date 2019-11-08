#ifndef _VISTAASFALTORECTO_H_
#define _VISTAASFALTORECTO_H_
#include "includes/cliente/VistaObjeto.h"
#include "includes/cliente/SdlTexture.h"

class VistaAsfaltoRecto : public VistaObjeto {
 public:
  VistaAsfaltoRecto(SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y, int angulo, int screenX, int screenY) override;
};
#endif

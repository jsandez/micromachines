#ifndef _VISTAOBJETOMOVIL_H_
#define _VISTAOBJETOMOVIL_H_
#include "includes/cliente/VistaObjeto.h"

class VistaObjetoMovil : public VistaObjeto {
 public:
  VistaObjetoMovil(int width, int height, int angulo, SdlTexture &sdl_texture);
  virtual void mover(int posX, int posY) override;
  virtual void rotar(int rotacion) override;
};
#endif

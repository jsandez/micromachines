#ifndef _VISTAOBJETODINAMICO_H_
#define _VISTAOBJETODINAMICO_H_
#include "includes/cliente/VistaObjeto.h"
class VistaObjetoDinamico : public VistaObjeto {
 private:
  int x, y, angulo;
 public:
  VistaObjetoDinamico(SdlTexture &sdl_texture, int x, int y, int angulo);
  virtual void mover(int x, int y, int angulo) override;
  int getX() const override;
  int getY() const override;
  int getAngulo() const override;
};
#endif

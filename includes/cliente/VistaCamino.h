#ifndef _VISTACAMINO_H_
#define _VISTACAMINO_H_
#include "includes/cliente/"

class VistaCamino : public VistaObjeto {
 public:
  VistaCamino(int x, int y, int angulo, SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y);
};

#endif

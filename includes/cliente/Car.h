#ifndef _AUTO_H_
#define _AUTO_H_
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "includes/cliente/VistaObjeto.h"

class Car : public VistaObjeto {
 public:
  Car(int width, int height, SdlTexture &sdl_texture);
  virtual void dibujar(int x, int y) override;
  virtual void mover(int x, int y) override;
  virtual void rotar(int rotacion) override;
};

#endif

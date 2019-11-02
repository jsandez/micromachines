#include <stdexcept>
#include "includes/cliente/VistaObjeto.h"

VistaObjeto::VistaObjeto(SdlTexture &sdl_texture) : textura(sdl_texture) {}

int VistaObjeto::getX() {
  return x;
}

int VistaObjeto::getY() {
  return y;
}

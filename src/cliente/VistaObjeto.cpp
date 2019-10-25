#include "includes/cliente/VistaObjeto.h"

VistaObjeto::VistaObjeto(int width, int height, SdlTexture &sdl_texture)
    : width(width), height(height), textura(sdl_texture) {
  this->x = 0;
  this->y = 0;
}

int VistaObjeto::getX() {
  return x;
}

int VistaObjeto::getY() {
  return y;
}

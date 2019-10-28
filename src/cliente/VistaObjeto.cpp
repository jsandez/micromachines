#include <stdexcept>
#include "includes/cliente/VistaObjeto.h"

VistaObjeto::VistaObjeto(int width, int height, int angulo, SdlTexture &sdl_texture)
    : width(width), height(height), angulo(angulo), textura(sdl_texture) {
  this->x = 0;
  this->y = 0;
}

void VistaObjeto::mover(int posX, int posY) {
  throw std::runtime_error("Intentando mover objeto incorrecto");
}

void VistaObjeto::rotar(int rotacion) {
  throw std::runtime_error("Intentando rotar objeto incorrecto");
}

int VistaObjeto::getX() {
  return x;
}

int VistaObjeto::getY() {
  return y;
}

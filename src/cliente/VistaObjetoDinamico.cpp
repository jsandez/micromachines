#include "includes/cliente/VistaObjetoDinamico.h"

VistaObjetoDinamico::VistaObjetoDinamico(SdlTexture &sdl_texture, int x, int y, int angulo) :
    VistaObjeto(sdl_texture), x(x), y(y), angulo(angulo) {}

void VistaObjetoDinamico::mover(int x, int y, int angulo) {
  this->x += x;
  this->y += y;
  this->angulo = angulo;
}

int VistaObjetoDinamico::getX() const {
  return x;
}

int VistaObjetoDinamico::getY() const {
  return y;
}

int VistaObjetoDinamico::getAngulo() const {
  return angulo;
}
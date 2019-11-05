#include <stdexcept>
#include "includes/cliente/VistaObjeto.h"

VistaObjeto::VistaObjeto(SdlTexture &sdl_texture)
    : textura(sdl_texture) {}

void VistaObjeto::mover(int posX, int posY, int angulo) {
  throw std::runtime_error("Intentando mover objeto incorrecto");
}

int VistaObjeto::getX() const {
  throw std::runtime_error("Intentando mover objeto incorrecto");
}

int VistaObjeto::getY() const {
  throw std::runtime_error("Intentando mover objeto incorrecto");
}

int VistaObjeto::getAngulo() const {
  throw std::runtime_error("Intentando mover objeto incorrecto");
}

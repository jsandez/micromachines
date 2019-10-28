#include "includes/cliente/VistaObjetoMovil.h"

VistaObjetoMovil::VistaObjetoMovil(int width, int height, int angulo, SdlTexture &sdl_texture) :
    VistaObjeto(width, height, angulo, sdl_texture) {}

void VistaObjetoMovil::mover(int posX, int posY) {
  this->x += posX;
  this->y += posY;
}

void VistaObjetoMovil::rotar(int rotacion) {
  this->angulo = rotacion;
}
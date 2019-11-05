#include "includes/cliente/VistaAuto.h"

VistaAuto::VistaAuto(SdlTexture &sdl_texture, int x, int y, int angulo) :
    VistaObjetoDinamico(sdl_texture, x, y, angulo) {
  this->
      width = 80;
  this->
      height = 100;
}

void VistaAuto::dibujar(int x, int y, int angulo, int screenX, int screenY) {
  Area src_area(0, 0, 463, 1010);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, angulo, SDL_FLIP_NONE);
}


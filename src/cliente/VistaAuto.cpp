#include "includes/cliente/VistaAuto.h"

VistaAuto::VistaAuto(int width, int height, int angulo, SdlTexture &sdl_texture) :
    VistaObjetoMovil(width, height, angulo, sdl_texture) {
}

void VistaAuto::dibujar(int x, int y) {
  Area src_area(0, 0, 463, 1010);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, this->angulo, SDL_FLIP_NONE);
}


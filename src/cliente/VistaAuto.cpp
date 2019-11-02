#include "includes/cliente/VistaAuto.h"

VistaAuto::VistaAuto(SdlTexture &sdl_texture) :
    VistaObjeto(sdl_texture) {
}

void VistaAuto::dibujar(int x, int y, int angulo) {
  Area src_area(0, 0, 463, 1010);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, angulo, SDL_FLIP_NONE);
}


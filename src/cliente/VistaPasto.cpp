#include "includes/cliente/VistaPasto.h"

VistaPasto::VistaPasto(int x, int y, int angulo, SdlTexture &sdl_texture) :
    VistaObjeto(x, y, angulo, sdl_texture) {}

void VistaPasto::dibujar(int x, int y) {
  Area src_area(x, y, 4096, 2160);
  Area dest_area(0, 0, this->width, this->height);
  this->textura.render(src_area, dest_area, this->angulo, SDL_FLIP_NONE);
}

#include "includes/cliente/VistaPasto.h"

VistaPasto::VistaPasto(SdlTexture &sdl_texture) :
    VistaObjeto(sdl_texture) {}

void VistaPasto::dibujar(int x, int y, int angulo, int screenX, int screenY) {
  Area src_area(0, 0, 256, 256);
  Area dest_area(x, y, 256, 256);
  this->textura.render(src_area, dest_area, angulo, SDL_FLIP_NONE);
}

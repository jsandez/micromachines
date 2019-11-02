#include "includes/cliente/VistaAsfaltoRecto.h"

VistaAsfaltoRecto::VistaAsfaltoRecto(SdlTexture &sdl_texture) :
    VistaObjeto(sdl_texture) {}

void VistaAsfaltoRecto::dibujar(int x, int y, int angulo) {
  Area src_area(0, 0, 256, 256);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, angulo, SDL_FLIP_NONE);
}

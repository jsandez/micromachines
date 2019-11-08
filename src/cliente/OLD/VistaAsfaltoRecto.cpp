#include "includes/cliente/VistaAsfaltoRecto.h"

VistaAsfaltoRecto::VistaAsfaltoRecto(SdlTexture &sdl_texture) :
    VistaObjeto(sdl_texture) {
  this->width = 256;
  this->height = 256;
}

void VistaAsfaltoRecto::dibujar(int x, int y, int angulo, int screenX, int screenY) {
  Area src_area(0, 0, this->width, this->height);
  Area dest_area(x, y, this->width, this->height);
  this->textura.render(src_area, dest_area, angulo, SDL_FLIP_NONE);
}

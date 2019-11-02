#include "includes/cliente/CreadorTexturas.h"
#include "includes/common/Constantes.h"
#include "includes/cliente/VistaTierra.h"

CreadorTexturas::CreadorTexturas(SdlWindow &sdl_window) :
    tierra("assets/111.png", sdl_window),
    pasto("assets/111.png", sdl_window),
    asfalto_recto("assets/111.png", sdl_window),
    asfalto_curva("assets/111.png", sdl_window),
    car("assets/111.png", sdl_window),
    salud("assets/111.png", sdl_window),
    boost("assets/111.png", sdl_window),
    piedra("assets/111.png", sdl_window),
    aceite("assets/111.png", sdl_window),
    barro("assets/111.png", sdl_window) {}

std::shared_ptr<VistaObjeto> CreadorTexturas::crear(int id) {
  std::shared_ptr<VistaObjeto> vistaObjeto;
  switch (id) {
    case ID_TIERRA: vistaObjeto.reset(new VistaTierra(this->tierra));break;
  }
  return vistaObjeto;
}


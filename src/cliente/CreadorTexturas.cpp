#include "includes/cliente/CreadorTexturas.h"
#include "includes/common/Constantes.h"
#include "includes/cliente/VistaTierra.h"
#include "includes/cliente/VistaAsfaltoRecto.h"
#include "includes/cliente/VistaAuto.h"

CreadorTexturas::CreadorTexturas(SdlWindow &sdl_window) :
    tierra("assets/111.png", sdl_window),
    pasto("assets/111.png", sdl_window),
    asfalto_recto("assets/1.png", sdl_window),
    asfalto_curva("assets/111.png", sdl_window),
    car("assets/pitstop_car_1.png", sdl_window),
    salud("assets/111.png", sdl_window),
    boost("assets/111.png", sdl_window),
    piedra("assets/111.png", sdl_window),
    aceite("assets/111.png", sdl_window),
    barro("assets/111.png", sdl_window) {}

// TODO: EN EL CREADOR DE TEXTURAS CREAMOS CADA  UNA, CREO QUE DEBERIAMOS PASARLE X,Y Y ANGULO
std::shared_ptr<VistaObjeto> CreadorTexturas::crear(int id) {
  std::shared_ptr<VistaObjeto> vistaObjeto;
  switch (id) {
    case ID_TIERRA:vistaObjeto.reset(new VistaTierra(this->tierra));
      break;
    case ID_ASFALTO_RECTO:vistaObjeto.reset(new VistaAsfaltoRecto(this->asfalto_recto));
      break;
    case ID_CAR:vistaObjeto.reset(new VistaAuto(this->car, 0, 0, -90));
      break;
  }
  return vistaObjeto;
}


#include "includes/cliente/VentanaPartida.h"

VentanaPartida::VentanaPartida(SdlWindow &window) :
    window(window),
    pista(),
    objetos(),
    autos(),
    consumibles(),
//    conversor(25.6, 256),
    creador_texturas(window) {
  terminado = false;
  deltaCamaraX = 0;
  deltaCamaraY = 0;
}

void VentanaPartida::crearPista() {
  objetos.push_back(creador_texturas.crear(100));
}

void VentanaPartida::dibujar() {
  for (std::shared_ptr<VistaObjeto> it : objetos) {
    it.get()->dibujar(0,0,0);
  }
  window.render();
}

void VentanaPartida::addAuto(VistaObjeto *car) {

}
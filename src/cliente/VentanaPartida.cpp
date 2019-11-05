#include "includes/cliente/VentanaPartida.h"
#include "includes/common/Constantes.h"

VentanaPartida::VentanaPartida(SdlWindow &window) :
    window(window),
    pista(1, 15, 15),
    texturasPista(),
    objetosDinamicos(),
    conversor(25.6, 256),
    camara(conversor, pista, objetosDinamicos),
    creador_texturas(window) {
  screenX = 0;
  screenY = 0;
  window.getWindowSize(&screenX, &screenY);
  camara.setWidthHeight(screenX, screenY);
  id_car = 0;
  crearPista();
}

void VentanaPartida::crearPista() {
  // DE ESTO SE ENCARGA EL JSON
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(ID_TIERRA, creador_texturas.crear(ID_TIERRA)));
  texturasPista.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(ID_ASFALTO_RECTO,
                                                                    creador_texturas.crear(ID_ASFALTO_RECTO)));
  for (int j = 0; j < 7; j++) {
    for (int i = 0; i < pista.getSizeX(); i++) {
      pista.agregarBloque(0, j, i, texturasPista.at(ID_TIERRA));
    }
  }

  for (int i = 0; i < pista.getSizeX(); i++) {
    pista.agregarBloque(0, 7, i, texturasPista.at(ID_ASFALTO_RECTO));
  }

  for (int j = 8; j < pista.getSizeY(); j++) {
    for (int i = 0; i < pista.getSizeX(); i++) {
      pista.agregarBloque(0, j, i, texturasPista.at(ID_TIERRA));
    }
  }
}

void VentanaPartida::dibujar() {
  camara.dibujarPista();
  std::shared_ptr<VistaObjeto> principalCar = objetosDinamicos[id_car];
  principalCar.get()->dibujar(screenX / 2,
                              screenY / 2,
                              principalCar.get()->getAngulo());
  camara.dibujarObjetos(id_car);
  window.render();
}

void VentanaPartida::addAutoPrincipal(std::shared_ptr<VistaObjeto> car, int id) {
  id_car = id;
  camara.setCar(car);
  objetosDinamicos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(id, car));
}

void VentanaPartida::addObjeto(std::shared_ptr<VistaObjeto> object, int id) {
  objetosDinamicos.insert(std::pair<int, std::shared_ptr<VistaObjeto>>(id, object));
}
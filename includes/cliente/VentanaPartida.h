#ifndef _VENTANAPARTIDA_H_
#define _VENTANAPARTIDA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/common/Conversor.h"
#include "includes/cliente/CreadorTexturas.h"
#include "includes/cliente/Pista.h"
#include <map>
#include <list>
#include <vector>

class VentanaPartida {
 private:
  SdlWindow &window;
  Pista pista;
  std::map<int, std::shared_ptr<VistaObjeto>> texturasPista;
  std::map<int, std::shared_ptr<VistaObjeto>> autos;
  std::map<int, std::shared_ptr<VistaObjeto>> consumibles;
  Conversor conversor;
  CreadorTexturas creador_texturas;
  bool terminado;
  int deltaCamaraX, deltaCamaraY;
  void crearPista();
 public:
  VentanaPartida(SdlWindow &window);
  void dibujar();

  // METODO TEMPORAL
  void addAuto(std::shared_ptr<VistaObjeto> car, int id);
};
#endif

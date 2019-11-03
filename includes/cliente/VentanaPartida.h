#ifndef _VENTANAPARTIDA_H_
#define _VENTANAPARTIDA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/common/Conversor.h"
#include "includes/cliente/CreadorTexturas.h"
#include <map>
#include <list>
#include <vector>

typedef struct Posicion Posicion_t;

struct Posicion {
  int x;
  int y;
};

class VentanaPartida {
 private:
  SdlWindow &window;
  std::map<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>> pista;
  std::map<int, std::shared_ptr<VistaObjeto>> texturasPista;
  std::map<int, std::shared_ptr<VistaObjeto>> autos;
  std::map<int, std::shared_ptr<VistaObjeto>> consumibles;
  Conversor conversor;
  CreadorTexturas creador_texturas;
  bool terminado;
  int deltaCamaraX, deltaCamaraY;

 public:
  VentanaPartida(SdlWindow &window);
  void dibujar();
  void crearPista();

  // METODO TEMPORAL
  void addAuto(std::shared_ptr<VistaObjeto> car);

};
#endif

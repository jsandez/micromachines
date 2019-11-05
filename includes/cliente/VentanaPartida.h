#ifndef _VENTANAPARTIDA_H_
#define _VENTANAPARTIDA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/Camara.h"
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
  std::map<int, std::shared_ptr<VistaObjeto>> objetosDinamicos;
  Conversor conversor;
  Camara camara;
  CreadorTexturas creador_texturas;
  int id_car, screenX, screenY;
  void crearPista();
  void dibujarPista(int xInicial, int xFinal, int yInicial, int yFinal, int deltaCamaraX, int deltaCamaraY);
  void dibujarObjetos(int xInicial, int xFinal, int yInicial, int yFinal, int deltaCamaraX, int deltaCamaraY);
 public:
  VentanaPartida(SdlWindow &window);
  void dibujar();
  // METODOS TEMPORAL
  void addAutoPrincipal(std::shared_ptr<VistaObjeto> car, int id);
  void addObjeto(std::shared_ptr<VistaObjeto> object, int id);
};
#endif

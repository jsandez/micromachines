#ifndef _VENTANAPARTIDA_H_
#define _VENTANAPARTIDA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/Camara.h"
#include "includes/common/Conversor.h"
#include "includes/cliente/CreadorTexturas.h"
#include "includes/cliente/Pista.h"
#include "includes/cliente/Ventana.h"
#include <map>
#include <list>
#include <vector>

class VentanaPartida : public Ventana {
 private:
  SdlWindow &window;
  Pista pista;
  std::map<int, std::shared_ptr<VistaObjeto>> texturasPista;
  // TODO: ESTO TIENE QUE SER UN MONITOR???
  std::map<int, std::shared_ptr<VistaObjeto>> objetosDinamicos;
  Conversor conversor;
  Camara camara;
  CreadorTexturas creador_texturas;
  int id_car, screenX, screenY;
  void crearPista();

 public:
  VentanaPartida(SdlWindow &window);
  void dibujar() override ;
  // METODOS TEMPORAL
  void addAutoPrincipal(std::shared_ptr<VistaObjeto> car, int id);
  void addObjeto(std::shared_ptr<VistaObjeto> object, int id);
};
#endif

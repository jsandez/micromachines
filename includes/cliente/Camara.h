#ifndef _CAMARA_H_
#define _CAMARA_H_
#include "includes/cliente/SdlWindow.h"
#include "includes/cliente/VistaObjeto.h"
#include "includes/cliente/Pista.h"
#include <memory>
#include "includes/common/Conversor.h"

class Camara {
 private:
  Conversor &conversor;
  Pista &pista;
  std::map<int, std::shared_ptr<VistaObjeto>> &objetosDinamicos;
  int width, height, xInicial, xFinal, yInicial, yFinal;
  std::shared_ptr<VistaObjeto> car;
  int deltaCamaraX();
  int deltaCamaraY();
 public:
  Camara(Conversor &conversor, Pista &pista, std::map<int, std::shared_ptr<VistaObjeto>> &objetosDinamicos);
  void setWidthHeight(int width, int height);
  void setCar(std::shared_ptr<VistaObjeto> car);
  void dibujarPista();
  void dibujarObjetos(int car_id);
};
#endif

#ifndef _PISTA_H_
#define _PISTA_H_
#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/cliente/GUI/Animacion.h"
#include "includes/cliente/GUI/AnimacionFactory.h"
#include <map>
#include <memory>
#include <vector>
#include <mutex>

class Pista {
 private:
  Renderizador &renderizador;
  uint16_t capas, size_x, size_y;
  std::map<int, std::vector<std::vector<std::shared_ptr<Animacion>>>> mapa;
  std::map<int, std::shared_ptr<Animacion>> texturas;
  std::map<int, std::shared_ptr<Animacion>> objetosDinamicos;
  std::mutex mtx_;

  // METODOS PRIVADOS PARA CREAR LA PISTA
  void agregarBloque(int capa, int x, int y, std::shared_ptr<Animacion> animacion);
  void crearPista(nlohmann::json pistaJson);

 public:
  Pista(std::string fileName, Renderizador &renderizador);
  void dibujate(int iteracion);
  std::shared_ptr<Animacion> getBloque(int capa, int x, int y) const;
  /*void agregarObjeto(int id, Animacion objetoDinamico);
  Animacion obtenerObjeto(int id);
  void obtenerIds(std::vector<int> &ids);
  void borrarObjeto(int id);*/
  int getSizeX() const;
  int getSizeY() const;
};

#endif


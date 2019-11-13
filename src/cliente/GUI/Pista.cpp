#include "includes/cliente/GUI/Pista.h"
#include <fstream>

void Pista::agregarBloque(int capa, int x, int y, std::shared_ptr<Animacion> animacion) {
  mapa[capa][x][y] = animacion;
}

void Pista::crearPista(nlohmann::json pistaJson) {
  // TODO: CREO QUE SE DEBERIA CAMBIAR LOS NOMBRES DEL JSON TERRENO Y PISTA POR NUMEROS
  // DE ESA FORMA NO ES NECESARIO SEPARAR EN DOS CICLOS DIFERENTES
  for (uint16_t i = 0; i < size_x; i++) {
    for (uint16_t j = 0; j < size_y; j++) {
      int bloqueTerreno = pistaJson["capas"]["terreno"][std::to_string(i)][std::to_string(j)].get<int>();
      if (bloqueTerreno != -1) {
        if (texturas.find(bloqueTerreno) == texturas.end()) {
          texturas.insert(std::pair<int, std::shared_ptr<Animacion>>(bloqueTerreno,
                                                                     std::make_shared<Animacion>(AnimacionFactory::instanciar(
                                                                         bloqueTerreno,
                                                                         renderizador))));
        }
        agregarBloque(0, i, j, texturas.at(bloqueTerreno));
      }
    }

    for (uint16_t i = 0; i < size_x; i++) {
      for (uint16_t j = 0; j < size_y; j++) {
        int bloqueTerreno = pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)].get<int>();
        if (bloqueTerreno != -1) {
          if (texturas.find(bloqueTerreno) == texturas.end()) {
            texturas.insert(std::pair<int, std::shared_ptr<Animacion>>(bloqueTerreno,
                                                                       std::make_shared<Animacion>(AnimacionFactory::instanciar(
                                                                           bloqueTerreno,
                                                                           renderizador))));
          }
          agregarBloque(1, i, j, texturas.at(bloqueTerreno));
        }
      }
    }
  }
}

Pista::Pista(std::string
             fileName, Renderizador &renderizador)
    : renderizador(renderizador), objetosDinamicos() {
  std::string rutaPista = fileName;
  std::ifstream archivoPista(rutaPista);
  Json pistaJson;
  archivoPista >> pistaJson;
  this->capas = pistaJson["dimensiones"]["capas"].get<uint16_t>();
  this->size_x = pistaJson["dimensiones"]["x"].get<uint16_t>();
  this->size_y = pistaJson["dimensiones"]["y"].get<uint16_t>();
  for (int i = 0; i < this->capas; i++) {
    std::vector<std::vector<std::shared_ptr<Animacion>>> matrix;
    for (int j = 0; j < this->size_x; j++) {
      std::vector<std::shared_ptr<Animacion>> array;
      for (int k = 0; k < this->size_y; k++) {
        array.emplace_back(nullptr);
      }
      matrix.push_back(array);
    }
    mapa.insert(std::pair<int, std::vector<std::vector<std::shared_ptr<Animacion>>>>(i, matrix));
  }
  crearPista(pistaJson);
}

void Pista::dibujate(int iteracion) {
  for (int k = 0; k < capas; k++) {
    for (int i = 0; i < size_x; i++) {
      for (int j = 0; j < size_y; j++) {
        std::shared_ptr<Animacion> animacion = getBloque(k, i, j);
        if (animacion != nullptr) {
          Area areaFondo = Area(i * animacion.get()->ancho(),
                                j * animacion.get()->alto(),
                                animacion.get()->ancho(),
                                animacion.get()->alto());
          renderizador.dibujar(animacion.get()->get(iteracion), areaFondo);
        }
      }
    }
  }
}

std::shared_ptr<Animacion> Pista::getBloque(int capa, int x, int y) const {
  return mapa.at(capa).at(x).at(y);
}

void Pista::agregarObjeto(int id, std::shared_ptr<ObjetoDinamico> objetoDinamico) {
  std::lock_guard<std::mutex> lck(mtx_);
  objetosDinamicos.insert(std::pair<int, std::shared_ptr<ObjetoDinamico>>(id, objetoDinamico));
}

std::shared_ptr<ObjetoDinamico> Pista::obtenerObjeto(int id) {
  std::lock_guard<std::mutex> lck(mtx_);
  if (objetosDinamicos.find(id) != objetosDinamicos.end()) {
    return objetosDinamicos.at(id);
  }
  return nullptr;
}

void Pista::obtenerIds(std::vector<int> &ids) {
  std::lock_guard<std::mutex> lck(mtx_);
  for (std::map<int, std::shared_ptr<ObjetoDinamico>>::iterator it = objetosDinamicos.begin();
       it != objetosDinamicos.end(); ++it) {
    ids.push_back(it->first);
  }
}

void Pista::borrarObjeto(int id) {
  std::lock_guard<std::mutex> lck(mtx_);
  if (objetosDinamicos.find(id) != objetosDinamicos.end()) {
    objetosDinamicos.erase(id);
  }
}

int Pista::getCapas() const {
  return capas;
}

int Pista::getSizeX() const {
  return size_x;
}

int Pista::getSizeY() const {
  return size_y;
}

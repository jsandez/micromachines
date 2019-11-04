#include "includes/cliente/Pista.h"

Pista::Pista(int capas, int size_x, int size_y) : mapa(), size_x(size_x), size_y(size_y) {
  for (int i = 0; i < capas; i++) {
    std::vector<std::vector<std::shared_ptr<VistaObjeto>>> matrix;
    for (int j = 0; j < size_x; j++) {
      std::vector<std::shared_ptr<VistaObjeto>> array;
      for (int k = 0; k < size_y; k++) {
        array.push_back(nullptr);
      }
      matrix.push_back(array);
    }
    mapa.insert(std::pair<int, std::vector<std::vector<std::shared_ptr<VistaObjeto>>>>(i, matrix));
  }
}

void Pista::agregarBloque(int capa, int x, int y, std::shared_ptr<VistaObjeto> vista) {
  mapa[capa][x][y] = vista;
}

std::shared_ptr<VistaObjeto> Pista::getBloque(int capa, int x, int y) const {
  return mapa.at(capa).at(x).at(y);
}

int Pista::getSizeX() const {
  return size_x;
}

int Pista::getSizeY() const {
  return size_y;
}

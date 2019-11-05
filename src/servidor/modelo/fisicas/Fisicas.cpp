#include "includes/servidor/modelo/fisicas/Fisicas.h"

Fisicas::Fisicas() :
    gravedad_(0, 0),
    mundoBox2D_(std::make_shared<b2World>(gravedad_)) {
}

Fisicas::~Fisicas() {
}

void Fisicas::generarSuelo(std::map<Tile, std::shared_ptr<Superficie>>& tileASuelo) {
    //TODO: Implementar: es arena tierra y pista.
}

void Fisicas::generarSuperficies(std::map<Tile, std::shared_ptr<Superficie>>& tileASuperficie) {
    //TODO: Implementar
}

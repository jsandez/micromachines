#include "includes/servidor/modelo/fisicas/Fisicas.h"
#include "includes/servidor/utils/ConfigServidor.h"

Fisicas::Fisicas() :
    gravedad_(0, 0),
    mundoBox2D_(std::make_shared<b2World>(gravedad_)),
    iteracion_(0) {
}

Fisicas::~Fisicas() {
}

void Fisicas::generarSuelo(std::map<Tile, std::shared_ptr<Superficie>>& tileASuelo) {
    //TODO: Implementar: es arena tierra y pista.
}

void Fisicas::generarSuperficies(std::map<Tile, std::shared_ptr<Superficie>>& tileASuperficie) {
    //TODO: Implementar
}

void Fisicas::step(uint32_t numeroIteracion) {
    mundoBox2D_->Step(asddas, CONFIG_SERVIDOR.iteracionesVelocidad(), CONFIG_SERVIDOR.iteracionesPosicion())
}

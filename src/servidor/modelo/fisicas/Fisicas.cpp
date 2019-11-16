#include "includes/servidor/modelo/fisicas/Fisicas.h"

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"

#include "includes/servidor/modelo/entidades/Vehiculo.h"

Fisicas::Fisicas(Cola<std::shared_ptr<Evento>>& eventosOcurridos) :
    gravedad_(0, 0),
    mundoBox2D_(std::make_shared<b2World>(gravedad_)),
    frecuencia_((double)1 / (double)CONFIG_SERVIDOR.simulacionesPorSegundo()),
    iteracion_(0),
    eventosOcurridos_(eventosOcurridos) {
}

Fisicas::~Fisicas() {
}

void Fisicas::generarSuelo(std::map<Tile, std::shared_ptr<Superficie>>& tileASuelo) {
    //TODO: Implementar: es arena tierra y pista.

}

/*void Fisicas::generarSuperficies(std::map<Tile, std::shared_ptr<Superficie>>& tileASuperficie) {
    //TODO: Implementar
}*/
void Fisicas::acelerar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->acelerando();
}

void Fisicas::desacelerar(uint8_t uuidVehiculo) {
    vehiculos_.at(uuidVehiculo)->frenando();
}
#include <iostream>
void Fisicas::agregarVehiculo(Vehiculo& vehiculo, Posicion& posicion) {
    vehiculos_.emplace(vehiculo.uuid(), std::make_shared<B2DVehiculo>(mundoBox2D_.get(), vehiculo));
    std::cout << "Agrego vehículo en físicas: " << unsigned(vehiculo.uuid()) << std::endl;
}



void Fisicas::step(uint32_t numeroIteracion) {
    //TODO: Todos haran step
    for (const auto& kv : vehiculos_) {
        kv.second->step();
    }

    uint32_t escala = numeroIteracion - iteracion_;
    double tiempoAtranscurrir = (double)escala * frecuencia_;
    mundoBox2D_->Step(tiempoAtranscurrir, CONFIG_SERVIDOR.iteracionesVelocidad(), CONFIG_SERVIDOR.iteracionesPosicion());
    iteracion_ = numeroIteracion;
    b2Body* actual = mundoBox2D_->GetBodyList();
    while (actual) {
        b2Vec2 position = actual->GetPosition();
		float32 angle = actual->GetAngle();
        printf("Vehiculo: 1");
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    
        std::cout << "Speed: " << actual->GetLinearVelocity().Length() << std::endl;
        actual = actual->GetNext();
    }
}


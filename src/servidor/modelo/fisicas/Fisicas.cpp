#include "includes/servidor/modelo/fisicas/Fisicas.h"

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"

#include "includes/servidor/modelo/Vehiculo.h"

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
void Fisicas::acelerar(uint32_t uuidVehiculo) {
    
}

void Fisicas::agregarVehiculo(Vehiculo& vehiculo, Posicion& posicion) {
    //TODO: Implementar
    /*b2Vehiculo* v = new b2Vehiculo(mundoBox2D_.get(), 100, -20, 150, 1, 2.5, 0 ,0);
    colisionables_[vehiculo.uuid()] = v->get();
    std::cout << vehiculo.uuid() << "agregad\n";*/
    /*b2BodyDef b2CuerpoDef;
    // Para simular mejor el movimiento
	b2CuerpoDef.bullet = true;
	b2CuerpoDef.type = b2_dynamicBody;
	b2CuerpoDef.position.Set(posicion.x_, posicion.y_);
//	b2CuerpoDef.userData = &unaEntidad;
	b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);

    b2PolygonShape b2FormaCaja;
	b2FormaCaja.SetAsBox(1, 1);
	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2FormaCaja;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);
	
	colisionables_[vehiculo.uuid()] = b2Cuerpo;*/
}

void Fisicas::step(uint32_t numeroIteracion) {
    //TODO: Todos haran step
    /*for (const auto& kv : colisionables_) {
        ((b2Vehiculo*)kv.second->GetUserData())->update();
    }*/

    uint32_t escala = numeroIteracion - iteracion_;
    double tiempoAtranscurrir = (double)escala * frecuencia_;
    mundoBox2D_->Step(tiempoAtranscurrir, CONFIG_SERVIDOR.iteracionesVelocidad(), CONFIG_SERVIDOR.iteracionesPosicion());
    iteracion_ = numeroIteracion;
    for (const auto& kv : colisionables_) {
        b2Vec2 position = kv.second->GetPosition();
		float32 angle = kv.second->GetAngle();
        printf("Vehiculo: %u ", kv.first);
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }    
}


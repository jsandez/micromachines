#include "includes/servidor/modelo/fisicas/B2DVehiculo.h"

#include "includes/3rd-party/Box2D/Box2D.h"
#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/utils/ConfigServidor.h"

B2DVehiculo::B2DVehiculo(b2World* mundoBox2D, Vehiculo& vehiculo)
    : volanteIzquierda_(0x1)
    , volanteDerecha_(0x2)
    , acelerador_(0x4)
    , freno_(0x8)
    , velocidadMaxAdelante_(vehiculo.velocidadMaximaAdelante())
    , velocidadMaxAtras_((-1)*vehiculo.velocidadMaximaAtras()) {
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    cuerpoBox2D_ = mundoBox2D->CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    float ancho = CONFIG_SERVIDOR.anchoVehiculo() / 2;
    float largo = CONFIG_SERVIDOR.largoVehiculo() / 2;
    polygonShape.SetAsBox(ancho, largo);
    b2Fixture* fixture = cuerpoBox2D_->CreateFixture(&polygonShape, 1);
    //TODO: Propiedades de la rueda, sublcase que tiene datos (?)
    //fixture->SetUserData( new CarTireFUD() );
    cuerpoBox2D_->SetUserData(&vehiculo);
    
    traccion_ = (float)vehiculo.agarre() / 100;
    fuerzaManejoMaxima_ = vehiculo.aceleracion() * 75;
}

B2DVehiculo::~B2DVehiculo() {
    cuerpoBox2D_->GetWorld()->DestroyBody(cuerpoBox2D_);
}

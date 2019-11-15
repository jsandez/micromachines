#include "includes/servidor/modelo/fisicas/B2DVehiculo.h"

#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/utils/ConfigServidor.h"

B2DVehiculo::B2DVehiculo(b2World* mundoBox2D, Vehiculo& vehiculo)
    : control_(0)
    , velocidadMaxAdelante_(vehiculo.velocidadMaximaAdelante())
    , velocidadMaxAtras_((-1)*vehiculo.velocidadMaximaAtras()) {
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    cuerpoBox2D_ = mundoBox2D->CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    float ancho = CONFIG_SERVIDOR.anchoVehiculo() / 2.0f;
    float largo = CONFIG_SERVIDOR.largoVehiculo() / 2.0f;
    polygonShape.SetAsBox(ancho, largo);
    b2Fixture* fixture = cuerpoBox2D_->CreateFixture(&polygonShape, 1);
    fixture->SetUserData(nullptr);
    //TODO: Propiedades de la rueda, sublcase que tiene datos (?)
    //fixture->SetUserData( new CarTireFUD() );
    cuerpoBox2D_->SetUserData(&vehiculo);
    
    traccion_ = (float)vehiculo.agarre() / 100.0f;
    fuerzaManejoMaxima_ = (float)vehiculo.aceleracion() * 0.75f;
}

B2DVehiculo::~B2DVehiculo() {
    cuerpoBox2D_->GetWorld()->DestroyBody(cuerpoBox2D_);
}

b2Vec2 B2DVehiculo::getVelocidadLateral() {
    b2Vec2 normal = cuerpoBox2D_->GetWorldVector(b2Vec2(1,0));
    return b2Dot(normal, cuerpoBox2D_->GetLinearVelocity()) * normal;
}

b2Vec2 B2DVehiculo::getVelocidadFrontal() {
    b2Vec2 normal = cuerpoBox2D_->GetWorldVector(b2Vec2(0,1));
    return b2Dot(normal, cuerpoBox2D_->GetLinearVelocity()) * normal;
}

void B2DVehiculo::actualizarFriccion() {
    //Derrape
    float maxImpulsoLateral = (3.0f/100.0f)*(float)CONFIG_SERVIDOR.maniobrabilidadVehiculo() + 1.0f;
    b2Vec2 impulso = cuerpoBox2D_->GetMass() * -getVelocidadLateral();
    if (impulso.Length() > maxImpulsoLateral) {
        impulso *= maxImpulsoLateral / impulso.Length();
    }        
    cuerpoBox2D_->ApplyLinearImpulse(traccion_*impulso, cuerpoBox2D_->GetWorldCenter(), true);

    float correccionAngular = (-0.49f/100.0f)*(float)CONFIG_SERVIDOR.maniobrabilidadVehiculo() + 0.5f;
    cuerpoBox2D_->ApplyAngularImpulse(traccion_*correccionAngular*cuerpoBox2D_->GetInertia()*-cuerpoBox2D_->GetAngularVelocity(), true);

    b2Vec2 normal = getVelocidadFrontal();
    float velocidadActual = normal.Normalize();
    float rozamientoFrenado = -CONFIG_SERVIDOR.agarreVehiculo()/40 * velocidadActual;
    cuerpoBox2D_->ApplyForce(traccion_ * rozamientoFrenado * normal, cuerpoBox2D_->GetWorldCenter(), true);
}

void B2DVehiculo::actualizarAceleracion() {
    // El control state llega de los eventos
    float velocidadObjetivo = 0;
    switch (control_ & (acelerador_|freno_)) {
        case acelerador_:
            velocidadObjetivo = velocidadMaxAdelante_;
            break;
        case freno_:
            velocidadObjetivo = velocidadMaxAtras_;
            break;
        default:
            break;
    }
    b2Vec2 normal = cuerpoBox2D_->GetWorldVector(b2Vec2(0,1));
    float velocidadActual = b2Dot(getVelocidadFrontal(),normal);
    float fuerza = 0;
    if (velocidadObjetivo > velocidadActual) {
        fuerza = fuerzaManejoMaxima_;
    } else if (velocidadObjetivo < velocidadActual) {
        fuerza = (-1)*fuerzaManejoMaxima_;
    } else {
        return;
    }
    cuerpoBox2D_->ApplyForce(traccion_ * fuerza * normal, cuerpoBox2D_->GetWorldCenter(), true);
}

void B2DVehiculo::actualizarVolante() {
    float torque = 0;
    switch (control_ & (volanteIzquierda_|volanteDerecha_)) {
        case volanteIzquierda_:
            torque = (0.15f)*CONFIG_SERVIDOR.maniobrabilidadVehiculo();
            break;
        case volanteDerecha_:
            torque = (-0.15f)*CONFIG_SERVIDOR.maniobrabilidadVehiculo();
            break;
        default:
            break;
    }
    cuerpoBox2D_->ApplyTorque(torque, true);
}

void B2DVehiculo::step() {
    actualizarFriccion();
    actualizarAceleracion();
    actualizarVolante();
}

void B2DVehiculo::acelerando() {
    control_ |= acelerador_;
}

void B2DVehiculo::frenando() {
    control_ &= ~acelerador_;
}

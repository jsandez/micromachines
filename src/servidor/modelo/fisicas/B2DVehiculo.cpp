#include "includes/servidor/modelo/fisicas/B2DVehiculo.h"

#include "includes/servidor/modelo/entidades/Vehiculo.h"
#include "includes/servidor/utils/ConfigServidor.h"

//TODO: Que la velocidad hacia atrás dependa de la hacia delante
B2DVehiculo::B2DVehiculo(b2World* mundoBox2D, Vehiculo& vehiculo)
    : control_(0)
    , velocidadMaxAdelante_((float)vehiculo.velocidadMaximaAdelante() * AJUSTE_VELOCIDAD)
    , velocidadMaxAtras_((-1)*(float)vehiculo.velocidadMaximaAtras() * AJUSTE_VELOCIDAD) {
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    cuerpoBox2D_ = mundoBox2D->CreateBody(&bodyDef);

    b2PolygonShape polygonShape;
    float ancho = CONFIG_SERVIDOR.anchoVehiculo() / 2.0f;
    float largo = CONFIG_SERVIDOR.largoVehiculo() / 2.0f;
    polygonShape.SetAsBox(ancho, largo);
    b2Fixture* fixture = cuerpoBox2D_->CreateFixture(&polygonShape, DENSIDAD);
    fixture->SetUserData(nullptr);
    //TODO: Propiedades de la rueda, sublcase que tiene datos (?)
    //fixture->SetUserData( new CarTireFUD() );
    cuerpoBox2D_->SetUserData(&vehiculo);
    
    //TODO: Revisar agarre
    traccion_ = (float)vehiculo.agarre() / 100.0f;
    fuerzaManejoMaxima_ = (float)vehiculo.aceleracion() * AJUSTE_ACELERACION;
}

B2DVehiculo::~B2DVehiculo() {
    cuerpoBox2D_->GetWorld()->DestroyBody(cuerpoBox2D_);
}

b2Vec2 B2DVehiculo::getVelocidadLateral() {
    b2Vec2 normal = cuerpoBox2D_->GetWorldVector(b2Vec2(1,0));
    return b2Dot(normal, cuerpoBox2D_->GetLinearVelocity()) * normal;
}

b2Body* B2DVehiculo::getB2D() {
    return cuerpoBox2D_;
}

b2Vec2 B2DVehiculo::getVelocidadFrontal() {
    b2Vec2 normal = cuerpoBox2D_->GetWorldVector(b2Vec2(0,1));
    return b2Dot(normal, cuerpoBox2D_->GetLinearVelocity()) * normal;
}

void B2DVehiculo::actualizarFriccion() {
    //Derrape
    float maxImpulsoLateral = MAX_IMPULSO_LATERAL;
    b2Vec2 impulso = cuerpoBox2D_->GetMass() * -getVelocidadLateral();
    if (impulso.Length() > maxImpulsoLateral) {
        impulso *= maxImpulsoLateral / impulso.Length();
    }        
    cuerpoBox2D_->ApplyLinearImpulse(traccion_*impulso, cuerpoBox2D_->GetWorldCenter(), true);

    cuerpoBox2D_->ApplyAngularImpulse(traccion_ * CORRECCION_DERRAPE * cuerpoBox2D_->GetInertia() * -cuerpoBox2D_->GetAngularVelocity(), true);

    b2Vec2 normal = getVelocidadFrontal();
    float velocidadActual = normal.Normalize();
    float rozamientoFrenado = -(fuerzaManejoMaxima_/velocidadMaxAdelante_)*velocidadActual;
    cuerpoBox2D_->ApplyForce(rozamientoFrenado * normal, cuerpoBox2D_->GetWorldCenter(), true);
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
            torque = AJUSTE_VOLANTE*(float)CONFIG_SERVIDOR.maniobrabilidadVehiculo();
            break;
        case volanteDerecha_:
            torque = (-AJUSTE_VOLANTE)*(float)CONFIG_SERVIDOR.maniobrabilidadVehiculo();
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
#include <iostream>
void B2DVehiculo::acelerando() {
    std::cout << "AcenerandoServer\n";
    control_ |= acelerador_;
}

void B2DVehiculo::desacelerando() {
    control_ &= ~acelerador_;
    std::cout << "DesacelerandoServer\n";
}

void B2DVehiculo::frenando() {
    control_ |= freno_;
    std::cout << "FrenandoServer\n";
}

void B2DVehiculo::dejandoDeFrenar() {
    control_ &= ~freno_;
    std::cout << "DesFrenandoServer\n";
}

void B2DVehiculo::doblandoIzquierda() {
    control_ |= volanteIzquierda_;
    std::cout << "DoblandoIzquierdaServer\n";
}

void B2DVehiculo::dejandoDeDoblarIzquierda() {
    control_ &= ~volanteIzquierda_;
    std::cout << "DesdoblandoizquierdaServer\n";
}

void B2DVehiculo::doblandoDerecha() {
    control_ |= volanteDerecha_;
    std::cout << "DoblandoDerechaServer\n";
}

void B2DVehiculo::dejandoDeDoblarDerecha() {
    control_ &= ~volanteDerecha_;
    std::cout << "DesdoblandoDerechaServer\n";
}

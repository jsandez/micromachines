#ifndef _B2D_VEHICULO_H_
#define _B2D_VEHICULO_H_

#include <cstdint>

#include "includes/3rd-party/Box2D/Box2D.h"

//Forward declarations
class b2Body;
class b2World;

class Vehiculo;

class B2DVehiculo {
private:
    static const uint8_t volanteIzquierda_ = 0x1;
    static const uint8_t volanteDerecha_ = 0x2;
    static const uint8_t acelerador_ = 0x4;
    static const uint8_t freno_ = 0x8;
    int control_;

    b2Body* cuerpoBox2D_;

    float velocidadMaxAdelante_;
    float velocidadMaxAtras_;
    // Fuerza que se aplica para acelerar/frenar el auto
    float fuerzaManejoMaxima_;
    // AKA rozamiento, agarre
    float traccion_;

public:
    B2DVehiculo(b2World* mundoBox2D, Vehiculo& vehiculo);
    ~B2DVehiculo();
    b2Vec2 getVelocidadLateral();
    b2Vec2 getVelocidadFrontal();
    void actualizarFriccion();
    void actualizarAceleracion();
    void actualizarVolante();
    void step();
    void acelerando();
    void frenando();
};

#endif

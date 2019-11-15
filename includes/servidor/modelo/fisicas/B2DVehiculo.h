#ifndef _B2D_VEHICULO_H_
#define _B2D_VEHICULO_H_

#include <cstdint>

//Forward declarations
class b2Body;
class b2World;

class Vehiculo;

class B2DVehiculo {
private:
    uint8_t volanteIzquierda_;
    uint8_t volanteDerecha_;
    uint8_t acelerador_;
    uint8_t freno_;

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
};

#endif

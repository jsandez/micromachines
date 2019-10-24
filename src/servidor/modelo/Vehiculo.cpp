#include "includes/servidor/modelo/Vehiculo.h"

Vehiculo::Vehiculo(unsigned int velocidad_maxima,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            unsigned int salud) :
            velocidad_maxima_(velocidad_maxima),
            aceleracion_(aceleracion),
            maniobrabilidad_(maniobrabilidad),
            agarre_(agarre),
            salud_(salud) {
}

void Vehiculo::acelerar() {

}

void Vehiculo::frenar() {

}

void Vehiculo::doblarAIzquierda() {

}

void Vehiculo::doblarADerecha() {

}

#include "includes/servidor/modelo/entidades/Vehiculo.h"

Vehiculo::Vehiculo(unsigned int velocidadMaximaAdelante,
            unsigned int velocidadMaximaAtras,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            unsigned int salud) :
            velocidadMaximaAdelante_(velocidadMaximaAdelante),
            velocidadMaximaAtras_(velocidadMaximaAtras),
            aceleracion_(aceleracion),
            maniobrabilidad_(maniobrabilidad),
            agarre_(agarre),
            salud_(salud) {
}

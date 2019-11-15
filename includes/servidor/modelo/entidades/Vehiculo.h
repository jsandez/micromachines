#ifndef _VEHICULO_H_
#define _VEHICULO_H_

class Vehiculo {
private:
    unsigned int velocidadMaximaAdelante_;
    unsigned int velocidadMaximaAtras_;
    unsigned int aceleracion_;
    unsigned int maniobrabilidad_;
    unsigned int agarre_;
    unsigned int salud_;
    
public:
    Vehiculo(unsigned int velocidadMaximaAdelante,
            unsigned int velocidadMaximaAtras,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            unsigned int salud);
};

#endif

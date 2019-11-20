#ifndef _VEHICULO_H_
#define _VEHICULO_H_

#include "includes/servidor/modelo/Identificable.h"
#include "includes/servidor/modelo/Colisionable.h"

class Vehiculo : public Identificable, public Colisionable {
private:
    unsigned int velocidadMaximaAdelante_;
    unsigned int velocidadMaximaAtras_;
    unsigned int aceleracion_;
    unsigned int maniobrabilidad_;
    unsigned int agarre_;
    unsigned int salud_;
    
public:
    Vehiculo(uint8_t uuid,
            unsigned int velocidadMaximaAdelante,
            unsigned int velocidadMaximaAtras,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            unsigned int salud);

    unsigned int velocidadMaximaAdelante();
    unsigned int velocidadMaximaAtras();
    unsigned int aceleracion();
    unsigned int maniobrabilidad();
    unsigned int agarre();
    unsigned int salud();

    virtual void enColisionCon(Colisionable& otro) override;
    virtual void colisionarContra(Vehiculo& vehiculo) override;
};

#endif

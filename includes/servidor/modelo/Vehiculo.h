#ifndef _VEHICULO_H_
#define _VEHICULO_H_

class Vehiculo {
private:
    unsigned int velocidad_maxima_;
    unsigned int aceleracion_;
    unsigned int maniobrabilidad_;
    unsigned int agarre_;
    unsigned int salud_;
    
public:
    Vehiculo(unsigned int velocidad_maxima,
            unsigned int aceleracion,
            unsigned int maniobrabilidad,
            unsigned int agarre,
            unsigned int salud);

    void acelerar();

    void frenar();

    void doblarAIzquierda();

    void doblarADerecha();
};

#endif

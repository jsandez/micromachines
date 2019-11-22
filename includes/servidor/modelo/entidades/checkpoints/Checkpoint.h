#ifndef _CHECKPOINT_H_
#define _CHECKPOINT_H_

#include "includes/servidor/modelo/Colisionable.h"
#include "includes/servidor/modelo/movimiento/Posicion.h"

class Checkpoint : public Colisionable {
private:
    Posicion puntoRespawn_;
    unsigned int id_;
    float ancho_;
    float alto_;

public:
    Checkpoint(unsigned int id, float ancho, float alto, Posicion& posicion);    
    virtual int getTipo() override;
    //Temporal, de test
    int getID() {
        return id_;
    }
    Posicion& posicion();
    float ancho();
    float alto();
};

#endif

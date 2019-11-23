#ifndef _CHECKPOINT_H_
#define _CHECKPOINT_H_

#include "includes/servidor/modelo/Colisionable.h"
#include "includes/servidor/modelo/movimiento/Posicion.h"

class Checkpoint : public Colisionable {
private:
    Posicion puntoRespawn_;
    int id_;
    int idDelSiguiente_;
    float ancho_;
    float alto_;

public:
    Checkpoint(int id, int idDelSiguiente, float ancho, float alto, Posicion& posicion);    
    virtual int getTipo() override;
    Posicion& posicion();
    float ancho();
    float alto();
    //Temporal, de test
    //FIXME: QUITAR ESTO
    int getID() {
        return id_;
    }
};

#endif

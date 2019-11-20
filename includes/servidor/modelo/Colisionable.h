#ifndef _COLISIONABLE_H_
#define _COLISIONABLE_H_

//Forward declarations
class Vehiculo;

class Colisionable {
public:
    virtual void enColisionCon(Colisionable& otro) = 0;
    virtual void colisionarContra(Vehiculo& vehiculo);
};

#endif

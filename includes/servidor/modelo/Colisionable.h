#ifndef _COLISIONABLE_H_
#define _COLISIONABLE_H_

class Colisionable {

public:
    enum tipos {
        VEHICULO_ = 0
    };
    
    virtual int getTipo() = 0;
    
};

#endif

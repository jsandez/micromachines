#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

#define UUID_EVENTO_CREAR_PARTIDA   1
#define UUID_EVENTO_DESCONEXION     2

class Evento {

public:
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo);
};

#endif

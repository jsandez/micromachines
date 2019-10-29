#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

#define UUID_EVENTO_CREAR_PARTIDA   1
#define UUID_EVENTO_DESCONEXION     2

class Evento {
private:
    uint32_t UUIDRemitente_;
public:
    Evento(uint32_t uuidRemitente);
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo) = 0;
};

#endif

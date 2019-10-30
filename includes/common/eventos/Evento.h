#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"
#include "includes/common/Handler.h"

#define UUID_EVENTO_CREAR_PARTIDA   1
#define UUID_EVENTO_DESCONEXION     2
#define UUID_EVENTO_ACELERAR        3

class Evento {
private:
    uint32_t UUIDRemitente_;
public:
    Evento(uint32_t uuidRemitente);
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo) = 0;
    virtual void actualizar(Handler& handler) = 0;
};

#endif

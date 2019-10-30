#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

//Forward declarations
class Handler;

#define UUID_EVENTO_CREAR_PARTIDA       1
#define UUID_EVENTO_PARTIDA_AGREGADA    2
#define UUID_EVENTO_DESCONEXION         3
#define UUID_EVENTO_ACELERAR            4

class Evento {
private:
    uint32_t UUIDRemitente_;
public:
    Evento(uint32_t uuidRemitente);
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo) = 0;
    virtual void actualizar(Handler& handler) = 0;
    uint32_t uuidRemitente();
};

#endif

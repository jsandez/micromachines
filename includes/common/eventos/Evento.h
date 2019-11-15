#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

//Forward declarations
class Handler;

#define UUID_EVENTO_CREAR_PARTIDA       1
#define UUID_EVENTO_PARTIDA_AGREGADA    2
#define UUID_EVENTO_UNIRSE_A_PARTIDA    3
#define UUID_EVENTO_INICIAR_PARTIDA     4
#define UUID_EVENTO_DESCONEXION         5
#define UUID_EVENTO_ACELERAR            6
#define UUID_EVENTO_DESACELERAR         7
#define UUID_EVENTO_ID_JUGADOR          8

// TODO: Crear constructor por movimiento
//TODO: Setear id en cada evento creado
// TODO: implementar envio y construccion
class Evento {
private:
    uint32_t UUIDRemitente_;
protected:
    uint16_t UUIDEvento_;
public:
    Evento(uint32_t uuidRemitente);
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo) = 0;
    virtual void actualizar(Handler& handler) = 0;
    uint32_t uuidRemitente();
};

#endif

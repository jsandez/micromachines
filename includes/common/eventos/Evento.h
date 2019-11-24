#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

//Forward declarations
class Handler;

#define UUID_EVENTO_ACELERAR                    1
#define UUID_EVENTO_DESACELERAR                 2
#define UUID_EVENTO_FRENAR                      3
#define UUID_EVENTO_DEJAR_DE_FRENAR             4
#define UUID_EVENTO_DOBLAR_IZQUIERDA            5
#define UUID_EVENTO_DEJAR_DE_DOBLAR_IZQUIERDA   6
#define UUID_EVENTO_DOBLAR_DERECHA              7
#define UUID_EVENTO_DEJAR_DE_DOBLAR_DERECHA     8

#define UUID_EVENTO_CREAR_PARTIDA               9
#define UUID_EVENTO_PARTIDA_AGREGADA            10
#define UUID_EVENTO_UNIRSE_A_PARTIDA            11
#define UUID_EVENTO_INICIAR_PARTIDA             12
#define UUID_EVENTO_DESCONEXION                 13
#define UUID_EVENTO_PARTIDA_INICIADA            14
#define UUID_EVENTO_SNAPSHOT                    15
#define UUID_EVENTO_FIN_CARRERA                 16


// TODO: Crear constructor por movimiento
//TODO: Setear id en cada evento creado
// TODO: implementar envio y construccion
// TODO: achicar para que el envio sea mas eficiente según el máximo de eventos
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

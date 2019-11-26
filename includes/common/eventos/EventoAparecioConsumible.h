#ifndef _EVENTO_APARECIO_CONSUMIBLE_H_
#define _EVENTO_APARECIO_CONSUMIBLE_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

#define UUID_PIEDRA     0
#define UUID_VIDA       1
#define UUID_ACEITE     2
#define UUID_BARRO      3
#define UUID_BOOST      4

class EventoAparecioConsumible : public Evento {
public:
    uint8_t uuidConsumible_;
    uint8_t tipoConsumible_;
    float xCoord_;
    float yCoord_;

    EventoAparecioConsumible(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoAparecioConsumible(uint8_t uuidConsumible, uint8_t tipoConsumible, float xCoord, float yCoord);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif

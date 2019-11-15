#ifndef _EVENTO_ID_JUGADOR_H_
#define _EVENTO_ID_JUGADOR_H_

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class EventoIDVehiculoDeJugador : public Evento {
public:
    uint8_t idDelVehiculo_;
    
    EventoIDVehiculoDeJugador(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoIDVehiculoDeJugador(uint8_t idDelVehiculo);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif

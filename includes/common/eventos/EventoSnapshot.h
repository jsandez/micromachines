#ifndef _EVENTO_SNAPSHOT_H_
#define _EVENTO_SNAPSHOT_H_

#include <map>

#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

typedef struct {
    uint16_t xCoord_;
    uint16_t yCoord_;
    uint16_t angulo_;
    uint8_t salud_;
    uint8_t visible_;
} datosVehiculo_;

class EventoSnapshot : public Evento {
public:
    //TODO: OPTIMIZAR?
    uint8_t cantidadVehiculos_;
    std::map<uint8_t, datosVehiculo_> idsADatosVehiculos_;
    
    EventoSnapshot(uint32_t uuidRemitente, Protocolo& protocolo);
    EventoSnapshot(std::map<uint8_t, datosVehiculo_>&& datos);
    virtual void enviarse(Protocolo& protocolo) override;
    virtual void actualizar(Handler& handler) override;
};

#endif

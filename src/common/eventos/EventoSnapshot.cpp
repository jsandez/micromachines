#include "includes/common/eventos/EventoSnapshot.h"

#include "includes/common/Handler.h"

EventoSnapshot::EventoSnapshot(uint32_t uuidRemitente, Protocolo& protocolo) :
    Evento(uuidRemitente) {
    cantidadVehiculos_ = protocolo.recibirNumUnsigned8();
    for (size_t i = 0; i < cantidadVehiculos_; i++) {
        uint8_t id = protocolo.recibirNumUnsigned8();
        uint16_t xCoord = protocolo.recibirNumUnsigned16();
        uint16_t yCoord = protocolo.recibirNumUnsigned16();
        uint16_t angulo = protocolo.recibirNumUnsigned16();
        uint8_t salud = protocolo.recibirNumUnsigned8();
        uint8_t visible = protocolo.recibirNumUnsigned8();
        idsADatosVehiculos_.emplace(id, datosVehiculo_{
            xCoord,
            yCoord,
            angulo,
            salud,
            visible
        });
    }
}

EventoSnapshot::EventoSnapshot(std::map<uint8_t, datosVehiculo_>&& datos) :
    Evento(0),
    cantidadVehiculos_(datos.size()) {        
    
    UUIDEvento_ = UUID_EVENTO_SNAPSHOT;
    idsADatosVehiculos_ = std::move(datos);
}

void EventoSnapshot::enviarse(Protocolo& protocolo) {
    protocolo.enviar(UUIDEvento_);
    protocolo.enviar(cantidadVehiculos_);
    for (const auto& kv : idsADatosVehiculos_) {
        //ID
        protocolo.enviar(kv.first);
        //DATOS
        protocolo.enviar(kv.second.xCoord_);
        protocolo.enviar(kv.second.yCoord_);
        protocolo.enviar(kv.second.angulo_);
        protocolo.enviar(kv.second.salud_);
        protocolo.enviar(kv.second.visible_);
    }
}

void EventoSnapshot::actualizar(Handler& handler) {
    handler.manejar(*this);
}

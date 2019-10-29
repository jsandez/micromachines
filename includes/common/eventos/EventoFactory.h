#ifndef _EVENTO_FACTORY_H_
#define _EVENTO_FACTORY_H_

#include <memory>


#include "includes/common/red/Protocolo.h"
#include "includes/common/eventos/Evento.h"
#include "includes/common/eventos/EventoCrearPartida.h"
#include "includes/common/eventos/EventoDesconexion.h"

#define ERROR_EVENTO_DESCONOCIDO "Error al instanciar evento, se utilizó un UUID desconocido."

class EventoFactory {
private:
public:
    static std::shared_ptr<Evento> instanciar(uint32_t uuidRemitente, Protocolo& protocolo);
};

#endif

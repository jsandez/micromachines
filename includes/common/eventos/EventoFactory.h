#ifndef _EVENTO_FACTORY_H_
#define _EVENTO_FACTORY_H_

#include <memory>

#include "includes/common/red/Protocolo.h"
#include "includes/common/eventos/Evento.h"
#include "includes/common/eventos/EventoPartidaIniciada.h"
#include "includes/common/eventos/EventoCrearPartida.h"
#include "includes/common/eventos/EventoUnirseAPartida.h"
#include "includes/common/eventos/EventoPartidaAgregada.h"
#include "includes/common/eventos/EventoIniciarPartida.h"
#include "includes/common/eventos/EventoDesconexion.h"
#include "includes/common/eventos/EventoAcelerar.h"
#include "includes/common/eventos/EventoDesacelerar.h"
#include "includes/common/eventos/EventoFrenar.h"
#include "includes/common/eventos/EventoDejarDeFrenar.h"
#include "includes/common/eventos/EventoDoblarIzquierda.h"
#include "includes/common/eventos/EventoDejarDeDoblarIzquierda.h"
#include "includes/common/eventos/EventoDoblarDerecha.h"
#include "includes/common/eventos/EventoDejarDeDoblarDerecha.h"
#include "includes/common/eventos/EventoSnapshot.h"
#include "includes/common/eventos/EventoFinCarrera.h"

#define ERROR_EVENTO_DESCONOCIDO "Error al instanciar evento, se utilizó un UUID desconocido."

class EventoFactory {
private:
public:
    static std::shared_ptr<Evento> instanciar(uint32_t uuidRemitente, Protocolo& protocolo);
};

#endif

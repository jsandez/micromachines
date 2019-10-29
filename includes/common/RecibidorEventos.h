#ifndef _RECIBIDOR_EVENTOS_H_
#define _RECIBIDOR_EVENTOS_H_

#include "includes/common/Hilo.h"
#include "includes/common/red/SocketTCP.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"
#include "includes/common/red/Protocolo.h"

class RecibidorEventos : public Hilo {
private:
    ColaBloqueante<std::shared_ptr<Evento>>& destino_;   
    bool& seguirCorriendo_;
    Protocolo protocolo_;
    //int UUIDJugador_;

    public:
    RecibidorEventos(SocketTCP& origen, ColaBloqueante<std::shared_ptr<Evento>>& destino, bool& seguirCorriendo);
    
    virtual void run() override;
};

#endif

#ifndef _DISTRIBUIDOR_EVENTOS_H_
#define _DISTRIBUIDOR_EVENTOS_H_

#include "includes/common/Hilo.h"
#include "includes/servidor/red/SalaDeEspera.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"

class DistribuidorEventos : public Hilo {
private:
    bool& seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>>& eventos_;
    SalaDeEspera& salaDeEspera_;    

    DistribuidorEventos(const DistribuidorEventos& otro) = delete;
    DistribuidorEventos(DistribuidorEventos&& otro) = delete;
    DistribuidorEventos& operator=(DistribuidorEventos&& otro) = delete;    
    DistribuidorEventos& operator=(const DistribuidorEventos& otro) = delete;

public:
    DistribuidorEventos(bool& seguirCorriendo, ColaBloqueante<std::shared_ptr<Evento>>& eventos, SalaDeEspera& salaDeEspera);

    ~DistribuidorEventos();

    virtual void run() override;
};

#endif

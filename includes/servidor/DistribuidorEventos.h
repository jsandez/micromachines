#ifndef _DISTRIBUIDOR_EVENTOS_H_
#define _DISTRIBUIDOR_EVENTOS_H_

#include "includes/common/Hilo.h"
#include "includes/common/Handler.h"
#include "includes/servidor/SalaDeEspera.h"
#include "includes/common/ColaBloqueante.h"
#include "includes/common/eventos/Evento.h"

class DistribuidorEventos : public Hilo, public Handler {
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

    virtual void manejar(Evento& e) override;

    virtual void manejar(EventoAcelerar& e) override;
    virtual void manejar(EventoCrearPartida& e) override;
    virtual void manejar(EventoDesconexion& e) override;
};

#endif

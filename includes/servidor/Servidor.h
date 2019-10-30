#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "includes/servidor/HiloAceptador.h"
#include "includes/servidor/SalaDeEspera.h"
#include "includes/servidor/DistribuidorEventos.h"

#include <string>

#define CARACTER_SALIR 'q'

class Servidor {
private:
    bool seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosRecibidos_;
    SalaDeEspera salaDeEspera_;
    HiloAceptador hiloAceptador_;
    DistribuidorEventos distribuidorEventos_;
    
public:
    Servidor(const std::string& puerto);
    void correr();
    void cerrar();
};

#endif

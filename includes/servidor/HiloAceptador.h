#ifndef _HILO_ACEPTADOR_H_
#define _HILO_ACEPTADOR_H_

#include <string>

#include "includes/common/Hilo.h"
#include "includes/common/red/SocketTCP.h"
#include "includes/servidor/red/SocketTCPServidor.h"
#include "includes/servidor/SalaDeEspera.h"

class HiloAceptador : public Hilo {

private:
    SocketTCPServidor sktAceptador_;
    SalaDeEspera& salaDeEspera_;
    bool& seguirCorriendo_;

    HiloAceptador(const HiloAceptador& otro) = delete;
    HiloAceptador(HiloAceptador&& otro) = delete;
    HiloAceptador& operator=(HiloAceptador&& otro) = delete;    
    HiloAceptador& operator=(const HiloAceptador& otro) = delete;
    
public:
    HiloAceptador(const std::string& puerto, bool& seguirCorriendo, SalaDeEspera& salaDeEspera);

    ~HiloAceptador();

    virtual void run() override;

    virtual void join() override;
};

#endif

#ifndef _HILO_ACEPTADOR_H_
#define _HILO_ACEPTADOR_H_

#include <vector>
#include <string>

#include "includes/common/Hilo.h"
#include "includes/common/red/SocketTCP.h"
#include "includes/servidor/red/SocketTCPServidor.h"

class HiloAceptador : public Hilo {

private:
    SocketTCPServidor sktAceptador_;
    std::vector<SocketTCP> socketsClientes_;

    HiloAceptador(const HiloAceptador& otro) = delete;
    HiloAceptador(HiloAceptador&& otro) = delete;
    HiloAceptador& operator=(HiloAceptador&& otro) = delete;    
    HiloAceptador& operator=(const HiloAceptador& otro) = delete;
    
public:
    HiloAceptador(const std::string& puerto);

    ~HiloAceptador();

    virtual void run() override;

    virtual void join() override;
};

#endif

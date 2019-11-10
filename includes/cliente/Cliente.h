#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <string>

#include "includes/common/RecibidorEventos.h"

#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Renderizador.h"
#include "includes/cliente/HiloDibujador.h"
#include "includes/cliente/red/SocketTCPCliente.h"

class Cliente {
private:
    Ventana ventana_;
    Renderizador renderizador_;
    HiloDibujador dibujador_;
    SocketTCPCliente socket_;
    RecibidorEventos recibidor_;

public:
    Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana, const std::string& host, const std::string& puerto);
    void correr();
    void cerrar();
    ~Cliente();
};

#endif

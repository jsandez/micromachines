#include "includes/common/RecibidorEventos.h"

#include <iostream>

#include "includes/common/eventos/EventoFactory.h"
#include "includes/common/excepciones/EventoDesconocidoError.h"

RecibidorEventos::RecibidorEventos(SocketTCP& socketOrigen, ColaBloqueante<std::shared_ptr<Evento>>& destino, bool& seguirCorriendo) :
    destino_(destino),
    seguirCorriendo_(seguirCorriendo),
    protocolo_(socketOrigen) {
}

void RecibidorEventos::run() {
    while(seguirCorriendo_) {
        try {
            std::shared_ptr<Evento> eventoRecibido(EventoFactory::instanciar(protocolo_));
            destino_.put(eventoRecibido);
        }
        catch(EventoDesconocidoError& e) {
            std::cerr << e.what() << '\n';
            continue;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            std::shared_ptr<Evento> desconexion(std::make_shared<EventoDesconexion>());
            destino_.put(desconexion);
            break;
        }   
    }
}

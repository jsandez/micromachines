#include "includes/common/RecibidorEventos.h"

#include <iostream>

RecibidorEventos::RecibidorEventos(SocketTCP& socketOrigen, ColaBloqueante<std::shared_ptr<Evento>>& destino, bool& seguirCorriendo) :
    destino_(destino),
    protocolo_(socketOrigen),
    seguirCorriendo_(seguirCorriendo) {
}

void RecibidorEventos::run() {
    while(seguirCorriendo_) {
        try {
            std::shared_ptr<Evento> eventoRecibido(std::make_shared<Evento>(protocolo_));
            //eventoRecibido->atributos["uuid"] = uuid_;
            destino_.put(eventoRecibido);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            std::shared_ptr<Evento> desconexion(std::make_shared<Evento>());
            destino_.put(desconexion);
            break;
        }       
    }
}

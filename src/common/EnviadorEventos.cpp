#include "includes/common/EnviadorEventos.h"

#include <iostream>

EnviadorEventos::EnviadorEventos(SocketTCP& socketDestino, ColaBloqueante<std::shared_ptr<Evento>>& origen, bool& seguirCorriendo) :
    origen_(origen),
    seguirCorriendo_(seguirCorriendo),
    protocolo_(socketDestino) {
}

void EnviadorEventos::run() {
    bool obtenido;
    std::shared_ptr<Evento> eventoAEnviar;
    while(seguirCorriendo_ && (obtenido = origen_.get(eventoAEnviar))) {
        try {
            eventoAEnviar->enviarse(protocolo_);
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            break;
        }        
    }
}

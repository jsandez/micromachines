#include "includes/servidor/Servidor.h"

#include <iostream>

Servidor::Servidor(const std::string& puerto) :
    seguirCorriendo_(true),
    salaDeEspera_(eventosRecibidos_),
    hiloAceptador_(puerto, seguirCorriendo_, salaDeEspera_),
    distribuidorEventos_(seguirCorriendo_, eventosRecibidos_, salaDeEspera_) {
}

void Servidor::correr() {
    hiloAceptador_.start();
    distribuidorEventos_.start();
    char c;
    while ((c = std::cin.get()) != CARACTER_SALIR) {
        // pass
    }
    seguirCorriendo_ = false;
    cerrar();
}

void Servidor::cerrar() {
    eventosRecibidos_.detener();
    hiloAceptador_.join();
    distribuidorEventos_.join();
}

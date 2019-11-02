#include "includes/servidor/Servidor.h"

#include <iostream>

Servidor::Servidor(const std::string& puerto) :
    salaDeEspera_(eventosRecibidos_),
    hiloAceptador_(puerto, salaDeEspera_),
    distribuidorEventos_(eventosRecibidos_, salaDeEspera_, coordinadorPartidas_),
    coordinadorPartidas_(salaDeEspera_) {
}

void Servidor::correr() {
    hiloAceptador_.iniciar();
    distribuidorEventos_.iniciar();
    char c;
    while ((c = std::cin.get()) != CARACTER_SALIR) {
        // pass
    }
    cerrar();
}

void Servidor::cerrar() {
    std::cout << "1\n";
    eventosRecibidos_.detener();
    std::cout << "2\n";
    hiloAceptador_.detener();
    hiloAceptador_.join();
    std::cout << "3\n";
    distribuidorEventos_.detener();
    distribuidorEventos_.join();
    std::cout << "4\n";
}

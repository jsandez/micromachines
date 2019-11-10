#include "includes/cliente/Cliente.h"

#include <iostream>

Cliente::Cliente(unsigned int anchoVentana, unsigned int altoVentana, bool pantallaCompleta, const std::string& tituloVentana, const std::string& host, const std::string& puerto) :
    ventana_(anchoVentana, altoVentana, pantallaCompleta, tituloVentana),
    renderizador_(ventana_),
    dibujador_(ventana_, renderizador_),
    socket_(host, puerto),
    recibidor_(socket_, dibujador_.eventosEntrantes(), 0) {
}

Cliente::~Cliente() {
    dibujador_.join();
    recibidor_.join();
}

void Cliente::correr() {
    try {
        socket_.conectar();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }   

    recibidor_.iniciar();
    dibujador_.iniciar();

    char c;
    while ((c = std::cin.get()) != 'q') {
        // pass
    }
    cerrar();
}

void Cliente::cerrar() {
    dibujador_.detener();
    recibidor_.detener();
    socket_.cerrarLectoEscritura();
}


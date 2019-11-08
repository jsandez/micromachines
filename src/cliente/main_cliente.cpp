#include <iostream>

#include "includes/cliente/Cliente.h"

int main(int argc, char *argv[]) {
    Cliente cliente;
    try {
        cliente.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
        return -1;
    }
    cliente.cerrar();
    return 0;
}

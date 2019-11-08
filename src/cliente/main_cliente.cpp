#include <iostream>

#include "includes/cliente/Cliente.h"

int main(int argc, char *argv[]) {
    Cliente cliente(argc, argv);
    int result = 0;
    try {
        result = cliente.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    cliente.cerrar();
    return result;
}
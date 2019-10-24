#include <iostream>

#include "includes/servidor/Servidor.h"
#include "includes/servidor/utils/ConfigServidor.h"

int main(int argc, char const *argv[]) {
    Servidor s(CONFIG_SERVIDOR.puertoServidor());
    try {
        s.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << CONFIG_SERVIDOR.puertoServidor() << '\n';
    return 0;
}

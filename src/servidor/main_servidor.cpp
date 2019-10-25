#include <iostream>

#include "includes/servidor/Servidor.h"
#include "includes/servidor/utils/ConfigServidor.h"

int main(int argc, char const *argv[]) {
    Servidor servidor(CONFIG_SERVIDOR.puertoServidor());
    try {
        servidor.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << CONFIG_SERVIDOR.puertoServidor();
    return 0;
}

#include <iostream>

#include "includes/servidor/Servidor.h"
#include "includes/servidor/utils/ConfigServidor.h"

int main(int argc, char const *argv[]) {
    Servidor s(200);
    try {
        s.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << 200 << '\n';
    return 0;
}

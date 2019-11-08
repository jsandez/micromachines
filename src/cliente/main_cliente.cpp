#include <iostream>
#include <QApplication>
#include <QLabel>

#include "includes/cliente/Cliente.h"

int main(int argc, char *argv[]) {
    Cliente cliente;
    try {
        cliente.correr();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    cliente.cerrar();
    QApplication aplicacion_(argc, argv);
    QLabel label("Hello QT");
    // Muestro el elemento
    label.show();
    return aplicacion_.exec();
}
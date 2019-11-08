#include "includes/cliente/Cliente.h"

#include <QLabel>

#include "includes/cliente/utils/ConfigCliente.h"

Cliente::Cliente(int& argc, char *argv[]) :
    QApplication(argc, argv){
}

int Cliente::correr() {
    QLabel label("Hello QT");
    label.show();
    return exec();
}

void Cliente::cerrar() {

}

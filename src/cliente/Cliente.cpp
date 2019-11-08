#include "includes/cliente/Cliente.h"

#include "includes/cliente/utils/ConfigCliente.h"

Cliente::Cliente() :
    ventana_(CONFIG_CLIENTE.anchoVentana(),
        CONFIG_CLIENTE.altoVentana(),
        CONFIG_CLIENTE.pantallaCompleta(),
        CONFIG_CLIENTE.tituloVentana()),
    renderizador_(ventana_) {
}

void Cliente::correr() {

}

void Cliente::cerrar() {

}

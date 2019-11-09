#include "includes/cliente/Cliente.h"

#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/GUI/Ventana.h"
#include "includes/cliente/GUI/Escena.h"

Cliente::Cliente() {
}

void Cliente::correr() {
    Ventana v(CONFIG_CLIENTE.anchoVentana(),
        CONFIG_CLIENTE.altoVentana(),
        CONFIG_CLIENTE.pantallaCompleta(),
        CONFIG_CLIENTE.tituloVentana());
    
    Renderizador r(v);
    Escena e(v, r);
}

void Cliente::cerrar() {

}

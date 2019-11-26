#include "includes/servidor/modelo/entidades/CajaVida.h"

CajaVida::CajaVida(uint8_t uuid) :
    Modificador(uuid) {

}

int CajaVida::getTipo() {
    return SALUD_;
}

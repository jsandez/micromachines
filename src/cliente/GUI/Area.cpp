#include "includes/cliente/GUI/Area.h"

Area::Area(unsigned int inicioAncho, unsigned int finAncho, unsigned int inicioAlto, unsigned int finAlto) :
    inicioAncho_(inicioAncho),
    finAncho_(finAncho),
    inicioAlto_(inicioAlto),
    finAlto_(finAlto) {

}

unsigned int Area::ancho() {
    return finAncho_ - inicioAncho_;
}
unsigned int Area::alto() {
    return finAlto_ - inicioAlto_;
}

#include "includes/cliente/Camara.h"

Camara::Camara(int width, int height, Conversor &conversor) :
        width(width),
        height(height),
        conversor(conversor) {}

void Camara::setCar(std::shared_ptr<VistaObjeto> car) {
    this->car = car;
}

int Camara::deltaCamaraX() {
    int deltaCamaraX = car.second.get()->getX();
    if (deltaCamaraX < width / 2) {
        // TODO: ESTO DE MOVER ES PARA Q NO TENGA  E Y NEGATIVO; CREO QUE VA DEL LADO DEL SERVER
        car.second.get()->mover((width / 2) - deltaCamaraX, 0, 0);
        deltaCamaraX = screenX / 2;
    }
    int limiteFinalX = conversor.bloqueAPixel(15) - (screenX / 2);
    int limiteFinalY = conversor.bloqueAPixel(15) - (screenY / 2);
    if (deltaCamaraX > limiteFinalX) {
        // TODO: ESTO DE MOVER ES PARA Q NO TENGA X E Y NEGATIVO; CREO QUE VA DEL LADO DEL SERVER
        car.second.get()->mover(-(deltaCamaraX - limiteFinalX), 0, 0);
        deltaCamaraX = limiteFinalX;
    }
    if (deltaCamaraY > limiteFinalY) {
        car.second.get()->mover(0, -(deltaCamaraY - limiteFinalY), 0);
        deltaCamaraY = limiteFinalY;
    }
}

int Camara::deltaCamaraY() {

}


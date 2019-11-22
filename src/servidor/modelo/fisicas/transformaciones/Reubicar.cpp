#include "includes/servidor/modelo/fisicas/transformaciones/Reubicar.h"

#include "includes/3rd-party/Box2D/Box2D.h"
#include "includes/servidor/modelo/movimiento/Posicion.h"

Reubicar::Reubicar(Fisicas& fisicas, b2Body* cuerpo, Posicion& posicion) :
    Transformacion(fisicas),
    cuerpo_(cuerpo),
    posicion_(posicion) {

}

void Reubicar::aplicar() {
    //FIXME: Obtener el angulo de la direccion
    cuerpo_->SetTransform(b2Vec2(posicion_.x_, posicion_.y_), 0.0);
}

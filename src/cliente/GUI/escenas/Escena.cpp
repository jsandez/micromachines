#include "includes/cliente/GUI/escenas/Escena.h"

Escena::Escena(std::stack<std::shared_ptr<Escena>>& escenas, Renderizador& renderizador) :
    escenas_(escenas),
    renderizador_(renderizador) {

}

Escena::~Escena() {

}

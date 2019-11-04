#include "includes/servidor/modelo/Identificable.h"

uint32_t Identificable::contadorUUID_ = 0;

uint32_t Identificable::proximoUUID() {
    std::lock_guard<std::mutex> lck(mutex_);
    return ++contadorUUID_;
}

Identificable::Identificable() : UUID_(proximoUUID()) {
}

Identificable::~Identificable() {
}

uint32_t Identificable::uuid() {
    return UUID_;
}

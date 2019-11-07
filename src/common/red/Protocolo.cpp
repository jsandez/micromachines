#include "includes/common/red/Protocolo.h"

Protocolo::Protocolo(SocketTCP& socket) :
    socket_(socket) {
}

uint16_t Protocolo::recibirNumUnsigned16() {
    uint16_t resultadoRed = 0;
    socket_.recibirN((char*) &resultadoRed, LEN_16);
    return ntohs(resultadoRed);
}

void Protocolo::enviar(uint16_t unNumero) {
    uint16_t numeroRed = htons(unNumero);
    socket_.enviarN((const char*) &numeroRed, LEN_16);
}

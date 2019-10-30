#ifndef _HANDLER_H_
#define _HANDLER_H_

// Forward declaration de los eventos
class Evento;
class EventoAcelerar;
class EventoCrearPartida;
class EventoDesconexion;

class Handler {
public:
    virtual void manejar(Evento& e) = 0;
    virtual void manejar(EventoAcelerar& e);
    virtual void manejar(EventoCrearPartida& e);
    virtual void manejar(EventoDesconexion& e);
};

#endif

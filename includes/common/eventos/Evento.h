#ifndef _EVENTO_H_
#define _EVENTO_H_

#include "includes/common/red/Protocolo.h"

#define UUID_EVENTO_CREAR_PARTIDA   1
#define UUID_EVENTO_DESCONEXION     2

class Evento {
protected:
    unsigned int UUIDEvento_;

public:
	Evento(unsigned int UUIDEvento);
    virtual ~Evento() {}
    virtual void enviarse(Protocolo& protocolo);

    
    //std::map<std::string, int> atributos;
	//virtual void enviarPorSocket(Socket& s) = 0;
	//virtual void actualizar(Handler& handler) = 0;
	//virtual ~Evento() {}
};

#endif

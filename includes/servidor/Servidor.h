#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

class Servidor {
private:
    unsigned int puerto_;

public:
    Servidor(unsigned int puerto);

    void correr();
};

#endif

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <QApplication>

class Cliente : public QApplication {

public:
    Cliente(int& argc, char *argv[]);
    int correr();
    void cerrar();
};

#endif

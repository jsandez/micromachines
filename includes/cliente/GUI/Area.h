#ifndef _AREA_H_
#define _AREA_H_

class Area {
private:
    unsigned int inicioAncho_;
    unsigned int finAncho_;
    unsigned int inicioAlto_;
    unsigned int finAlto_;
public:
    Area(unsigned int inicioAncho, unsigned int finAncho, unsigned int inicioAlto, unsigned int finAlto);

    unsigned int ancho();
    unsigned int alto();
};

#endif

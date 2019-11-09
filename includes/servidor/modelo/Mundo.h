#ifndef _MUNDO_H_
#define _MUNDO_H_

#include <memory>

#include "includes/common/Handler.h"
#include "includes/common/Cola.h"
#include "includes/servidor/modelo/fisicas/Fisicas.h"
#include "includes/common/Tile.h"
#include "includes/servidor/modelo/superficies/Superficie.h"

class Mundo : public Handler {
private:
    std::map<Tile, std::shared_ptr<Superficie>> tileASuelo_;
    std::map<Tile, std::shared_ptr<Superficie>> tileASuperficie_;
    Cola<std::shared_ptr<Evento>> eventosOcurridos_;
    Fisicas fisicas_;

public:
    //TODO: Mundo recibe referencia a partida para avisarle que termino.
    Mundo(uint16_t uuidPista);

    void step(uint32_t numeroIteracion);

    Cola<std::shared_ptr<Evento>>& eventosOcurridos();
    
    virtual void manejar(Evento& e) override;

    virtual void manejar(EventoAcelerar& e) override;
};

#endif

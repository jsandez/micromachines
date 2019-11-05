#include "includes/servidor/modelo/superficies/SuperficieFactory.h"

#include <algorithm>

#include "includes/servidor/utils/ConfigServidor.h"

std::shared_ptr<Superficie> SuperficieFactory::instanciar(int uuid) {
    
    std::vector<int>& tilesTierra = CONFIG_SERVIDOR.tilesTierra(); 
    std::vector<int>& tilesPista = CONFIG_SERVIDOR.tilesPista();
    
    int tileArena = CONFIG_SERVIDOR.tileArena();
    int tileBarro = CONFIG_SERVIDOR.tileBarro();
    int tileAceite = CONFIG_SERVIDOR.tileAceite();

    std::vector<int>::iterator it;

    it = std::find(tilesTierra.begin(), tilesTierra.end(), uuid);
    if (it != tilesTierra.end()) {
        return std::make_shared<SuperficieTierra>();
    }

    it = std::find(tilesPista.begin(), tilesPista.end(), uuid);
    if (it != tilesPista.end()) {
        return std::make_shared<SuperficiePista>();
    }

    if (uuid == tileArena) {
        return std::make_shared<SuperficieArena>();
    }

    if (uuid == tileBarro) {
        return std::make_shared<SuperficieBarro>();
    }

    if (uuid == tileAceite) {
        return std::make_shared<SuperficieAceite>();
    }
    
    return std::make_shared<NoSuperficie>();
}

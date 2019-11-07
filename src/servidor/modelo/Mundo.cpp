#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/common/Tile.h"
#include "includes/servidor/modelo/superficies/SuperficieFactory.h"

//Forward declaration
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuelo, Json& pistaJson);
static void cargarSuperficies(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuperficie, Json& pistaJson);

Mundo::Mundo(uint16_t uuidPista) {
    //TODO: Es mejor cargar todas las pistas al inicio y luego hacer un get() para no tener que ir
    // siempre a disco.
    std::string rutaPista = CONFIG_SERVIDOR.rutaPistas() + std::to_string(uuidPista) + ".json";
    std::ifstream archivoPista(rutaPista);
    Json pistaJson;
    archivoPista >> pistaJson;
    uint16_t x = pistaJson["dimensiones"]["x"].get<uint16_t>();
    uint16_t y = pistaJson["dimensiones"]["y"].get<uint16_t>();

    cargarSuelo(x, y, tileASuelo_, pistaJson);
    cargarSuperficies(x, y, tileASuperficie_, pistaJson);

    //TODO: Cargar posiciones de Vehículos
    
    fisicas_.generarSuelo(tileASuelo_);
    fisicas_.generarSuperficies(tileASuperficie_);
}

void Mundo::step(uint32_t numeroIteracion) {
    //TODO: implementar step
}

Cola<std::shared_ptr<Evento>>& Mundo::eventosOcurridos() {
    return eventosOcurridos_;
}

void Mundo::manejar(Evento& e) {
    e.actualizar(*this);
}

// El sistema de referencia de la pista está arriba a la izquierda,
// mientras que en el servidor está abajo a la derecha.
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuelo, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            int uuidTerreno = pistaJson["capas"]["terreno"][std::to_string(i)][std::to_string(j)].get<int>();
            int uuidPista = pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)].get<int>();
            // Hay pista
            if (uuidPista != CONFIG_SERVIDOR.tileVacio()) {
                tilesASuelo[Tile(i, largoY - j)] = SuperficieFactory::instanciar(uuidPista);
            } else {
                tilesASuelo[Tile(i, largoY - j)] = SuperficieFactory::instanciar(uuidTerreno);
            }
        }
    }
}

static void cargarSuperficies(uint16_t largoX, uint16_t largoY, std::map<Tile, std::shared_ptr<Superficie>>& tilesASuperficie, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            //TODO: Acá se usa el superficieFactory
            //TODO: Superficies son barro y aceite
            //tilesASuperficie[Tile(i, largoY - j)] = pistaJson["capas"]["superficies"][std::to_string(i)][std::to_string(j)];
        }
    }
}

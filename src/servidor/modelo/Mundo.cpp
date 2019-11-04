#include "includes/servidor/modelo/Mundo.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include "includes/servidor/utils/ConfigServidor.h"
#include "includes/3rd-party/jsoncpp/json.hpp"
#include "includes/common/Tile.h"

//Forward declaration
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile,uint16_t>& tilesASuelo, Json& pistaJson);
static void cargarSuperficies(uint16_t largoX, uint16_t largoY, std::map<Tile,uint16_t>& tilesASuperficie, Json& pistaJson);

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
    
    fisicas_.generarSuelo(tileASuelo_);
    fisicas_.generarSuperficies(tileASuperficie_);
}

// El sistema de referencia de la pista está arriba a la izquierda,
// mientras que en el servidor está abajo a la derecha.
static void cargarSuelo(uint16_t largoX, uint16_t largoY, std::map<Tile,uint16_t>& tilesASuelo, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            tilesASuelo[Tile(i, largoY - j)] = pistaJson["capas"]["terreno"][std::to_string(i)][std::to_string(j)];
            int idPista = pistaJson["capas"]["pista"][std::to_string(i)][std::to_string(j)];
            if (idPista != -1) {
                tilesASuelo[Tile(i, largoY - j)] = idPista;
            }
        }
    }
}

static void cargarSuperficies(uint16_t largoX, uint16_t largoY, std::map<Tile,uint16_t>& tilesASuperficie, Json& pistaJson) {
    for (uint16_t i = 0; i < largoX; ++i) {
        for (uint16_t j = 0; j < largoY; ++j) {
            tilesASuperficie[Tile(i, largoY - j)] = pistaJson["capas"]["superficies"][std::to_string(i)][std::to_string(j)];
        }
    }
}

/*Terreno desaparicion 116, 131
Terreno tierra 90 ... 115, 117 ... 130*/

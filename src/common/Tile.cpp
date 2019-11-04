#include "includes/common/Tile.h"

Tile::Tile(int x, int y) :
    x_(x),
    y_(y) {
}

bool Tile::operator<(const Tile& otro) const {
    return (this->x_ < otro.x_) && (this->y_ < otro.y_);
}

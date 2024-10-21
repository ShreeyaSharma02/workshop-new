#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.h"

class Ship : public GameEntity {
public:
    Ship(int x, int y) : GameEntity(x, y, GameEntityType::ShipType) {}

    // Move the ship by dx, dy
    void move(int dx, int dy) {
        int x, y;
        std::tie(x, y) = getPos();
        position = std::make_tuple(x + dx, y + dy);
    }
};

#endif // SHIP_H

#ifndef MINE_H
#define MINE_H

#include "GameEntity.h"
#include "Explosion.h"

class Mine : public GameEntity {
public:
    Mine(int x, int y) : GameEntity(x, y, GameEntityType::MineType) {}

    // Explode and return an Explosion object
    Explosion explode() {
        setType(GameEntityType::NoneType);  // Mark mine as exploded
        return Explosion(std::get<0>(position), std::get<1>(position));
    }

    void setType(GameEntityType newType) {
        type = newType;
    }
};

#endif // MINE_H

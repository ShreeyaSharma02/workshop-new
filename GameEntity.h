#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <tuple>

enum GameEntityType { ExplosionType, MineType, NoneType, ShipType };

class GameEntity {
protected:
    std::tuple<int, int> position;
    GameEntityType type;

public:
    GameEntity(int x, int y, GameEntityType entityType)
        : position(std::make_tuple(x, y)), type(entityType) {}

    virtual ~GameEntity() {}  // Make the class polymorphic by adding a virtual destructor

    std::tuple<int, int> getPos() const { return position; }
    GameEntityType getType() const { return type; }
};

#endif // GAMEENTITY_H

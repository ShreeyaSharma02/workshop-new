#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Effect.h"
#include "GameEntity.h"

class Explosion : public GameEntity, public Effect {
public:
    Explosion(int x, int y) : GameEntity(x, y, GameEntityType::ExplosionType) {}

    // Apply explosion effect to another GameEntity (e.g., Ship)
    void apply(GameEntity& entity) override {
        entity = GameEntity(-1, -1, GameEntityType::NoneType);  // Set entity as destroyed
    }
};

#endif // EXPLOSION_H

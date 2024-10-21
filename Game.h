#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game {
private:
    std::vector<GameEntity*> entities;

public:
    // Getter for entities
    std::vector<GameEntity*>& get_entities() {
        return entities;
    }

    // Setter for entities
    void set_entities(const std::vector<GameEntity*>& new_entities) {
        entities = new_entities;
    }

    // Initialize the game
    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        // Create ships
        for (int i = 0; i < numShips; i++) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(std::get<0>(pos), std::get<1>(pos)));
        }
        // Create mines
        for (int i = 0; i < numMines; i++) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(std::get<0>(pos), std::get<1>(pos)));
        }
        return entities;
    }

    // Game loop
    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int iteration = 0; iteration < maxIterations; iteration++) {
            // Move all ships
            for (auto entity : entities) {
                Ship* ship = dynamic_cast<Ship*>(entity);
                if (ship && ship->getPos() != std::make_tuple(-1, -1)) {
                    ship->move(1, 0);
                }
            }

            // Check for explosions
            for (auto entity1 : entities) {
                Ship* ship = dynamic_cast<Ship*>(entity1);
                if (ship && ship->getPos() != std::make_tuple(-1, -1)) {
                    for (auto entity2 : entities) {
                        Mine* mine = dynamic_cast<Mine*>(entity2);
                        if (mine) {
                            double distance = Utils::calculateDistance(ship->getPos(), mine->getPos());
                            if (distance <= mineDistanceThreshold) {
                                Explosion explosion = mine->explode();
                                explosion.apply(*ship);
                                break;
                            }
                        }
                    }
                }
            }

            // Check if all ships are destroyed
            bool allShipsDestroyed = true;
            for (auto entity : entities) {
                Ship* ship = dynamic_cast<Ship*>(entity);
                if (ship && std::get<0>(ship->getPos()) != -1) {
                    allShipsDestroyed = false;
                    break;
                }
            }

            if (allShipsDestroyed) {
                return;
            }
        }
    }
};

#endif // GAME_H

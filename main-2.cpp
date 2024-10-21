#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    Ship ship(5, 5);
    Mine mine(6, 6);

    // Move the ship
    ship.move(1, 0);
    std::cout << "Ship moved to position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";

    // Mine explodes
    Explosion explosion = mine.explode();
    explosion.apply(ship);
    std::cout << "Ship destroyed at position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";

    return 0;
}

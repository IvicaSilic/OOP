#include <iostream>
#include "Player.h"

Player::Player(const std::string& n, Level* l) : name(n), level(l) {}

void Player::print() const {
    std::cout << "Igrac: " << name << '\n';
    std::cout << "Level: neprijatelja " << level->enemy_count()
              << ", oruzja " << level->weapon_count() << '\n';
}

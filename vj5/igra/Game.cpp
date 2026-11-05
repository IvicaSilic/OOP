#include <iostream>
#include "Game.h"

Game::Game(const std::string& t, const std::string& player_name)
    : title(t), level(Enemy(100)), player(player_name, &level) {}

void Game::print() const {
    std::cout << title << '\n';
    player.print();
}

#include "Level.h"

Level::Level(const Enemy& first) : enemies(1, first) {}

int Level::enemy_count() const { return static_cast<int>(enemies.size()); }

int Level::weapon_count() const { return static_cast<int>(weapons.size()); }

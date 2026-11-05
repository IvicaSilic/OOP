#pragma once      
#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level {
 
    std::vector<Enemy> enemies;   
    std::vector<Weapon> weapons;  

public:

    explicit Level(const Enemy& first);
    int enemy_count() const;
    int weapon_count() const;
};

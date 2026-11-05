#pragma once      

#include <string>
#include "Level.h"

class Player {
    // data memberi
    std::string name;
    Level* level;   

public:
    // konstruktor
    Player(const std::string& n, Level* l);
    void print() const;
};

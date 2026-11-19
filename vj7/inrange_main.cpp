// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ovdje kopirajte Vec2 i operatore iz zadatka 1
struct Vec2{
public:
    int x,y;

    Vec2& operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};


Vec2 operator+(Vec2 a, const Vec2& b)
{
    return a += b;
}

Vec2 operator-(Vec2 a, const Vec2& b)
{
    return a -= b;
}

Vec2 operator*(Vec2 v, int k)
{
    v.x *= k;
    v.y *= k;
    return v;
}

Vec2 operator*(int k, const Vec2& v)
{
    return v * k;
}

bool operator==(const Vec2& a, const Vec2& b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b)
{
    return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Vec2& v)
{
    return out << "(" << v.x << ", " << v.y << ")";
}

// ovdje napisite struct Enemy
struct Enemy {
    std::string name;
    Vec2 pos;
};

// ovdje napisite klasu InRange
class InRange {
private:
    Vec2 centar;
    int domet;

public:
    InRange(Vec2 centar, int domet) : centar(centar), domet(domet) {}

    bool operator()(const Enemy& e) const {
        Vec2 d = e.pos - centar;
        return d.x * d.x + d.y * d.y <= domet * domet;
    }
};

int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    /* ovdje pozovite count_if s funkcijskim objektom */
    std::cout << std::count_if(enemies.begin(), enemies.end(), near) << '\n';
    int range = 2;

    /* ovdje pozovite count_if s lambdom */
    std::cout << std::count_if(enemies.begin(), enemies.end(), [player, range](const Enemy& e) {
        Vec2 d = e.pos - player;
        return d.x * d.x + d.y * d.y <= range * range;
    }) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/

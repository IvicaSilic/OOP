// Vjezba 7, zadatak 1: napisite strukturu Vec2 i operatore iznad main.
// 1. Položaj na ploči igre zapisuje se kao par cijelih brojeva. Napišite strukturu Vec2 s javnim
// članovima x i y (struct: jednostavna skupina podataka bez invarijante) i operatore:
// ◦+= i -= kao metode; vraćaju *this;
// ◦+ i - kao globalne funkcije, napisane preko += i -=;
// ◦množenje cijelim brojem s obje strane: v * 3 i 3 * v;
// ◦== i !=;
// ◦<< koji ispisuje (x, y).
// Program za testiranje je u datoteci vec2_main.cpp (očekivani ispis je na dnu datoteke).
#include <iostream>

// ovdje napisite Vec2 i operatore
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

int main()
{
    Vec2 player{2, 3};
    Vec2 right{1, 0};
    Vec2 down{0, 1};

    player += right;
    std::cout << player << '\n';
    player += 2 * down;
    std::cout << player << '\n';
    Vec2 target = player + right * 3 - down;
    std::cout << target << '\n';

    Vec2 enemy{6, 4};
    std::cout << (target == enemy) << ' ' << (player != enemy) << '\n';
    std::cout << player << " -> " << target << '\n';
    return 0;
}

/*
Ocekivani ispis:

    (3, 3)
    (3, 5)
    (6, 4)
    1 1
    (3, 5) -> (6, 4)
*/

#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy)
{
    p->x = p->x + dx;
    p->y = p->y + dy;
}

double dist(const Point* a, const Point* b)
{
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}

// pomocu referenci
void move_by_ref(Point& p, double dx, double dy)
{
    p.x = p.x + dx;
    p.y = p.y + dy;
}

double dist_ref(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    Point p;
    p.x = 1.0;
    p.y = 2.0;

    move_by(&p, 2.0, 3.0);
    std::cout << "Pointer: (" << p.x << ", " << p.y << ")" << std::endl;

    move_by_ref(p, -1.0, -1.0);
    std::cout << "Referenca: (" << p.x << ", " << p.y << ")" << std::endl;

    Point ishodiste;
    ishodiste.x = 0.0;
    ishodiste.y = 0.0;
    std::cout << "Udaljenost (pointer): " << dist(&p, &ishodiste) << std::endl;
    std::cout << "Udaljenost (referenca): " << dist_ref(p, ishodiste) << std::endl;

    Point tocke[5] = {{3.0, 4.0}, {-1.0, 1.0}, {5.0, -2.0}, {0.5, 0.5}, {2.0, 2.0}};
    int najblizi = 0;
    for (int i = 1; i < 5; i++)
    {
        if (dist_ref(tocke[i], ishodiste) < dist_ref(tocke[najblizi], ishodiste))
        {
            najblizi = i;
        }
    }
    std::cout << "Najblize ishodistu: (" << tocke[najblizi].x << ", "
              << tocke[najblizi].y << ")" << std::endl;

    return 0;
}

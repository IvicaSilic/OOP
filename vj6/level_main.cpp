// Vjezba 6, zadatak 5: napisite klase Enemy i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase Enemy i Level

class Enemy{
private:
    std::string name;
    int x;
    int y;
    int health=100;
public: 

    Enemy(std::string n,int xx, int yy) : name(n), x(xx),y(yy){}

    std::string get_name() const {return name;}
    int get_x() const {return x;}
    int get_y() const {return y;}
    int get_health() const{return health;}
    bool is_alive() const {return health>0;}

    void take_damage(int d){
        if (health-d<=0){
            health=0;
            return;
        }
        health-=d;
    }

    void move(int dx, int dy){
        x += dx;
        y += dy;
    }
};


class Level{
private:
    int rows;
    int cols;
    std::vector<Enemy> enemies;
public:
    Level(int r, int c) : rows(r), cols(c) {}

    bool add(Enemy r){
        if (r.get_x() >= 0 && r.get_x() < cols && r.get_y() >= 0 && r.get_y() < rows){
            enemies.push_back(r);
            return true;
        }
        return false;   
    }

    void step(int dx, int dy){
    for (Enemy& e : enemies){
        int nx = e.get_x() + dx;
        int ny = e.get_y() + dy;
        if (nx >= 0 && nx < cols && ny >= 0 && ny < rows){
            e.move(dx, dy);
        }
    }
    }

    void print() const {
        for (const auto& e : enemies){
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") " << e.get_health() << std::endl;
        }
    }


};







int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/

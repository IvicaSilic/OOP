// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase
// 2. U igri postoji više vrsta neprijatelja, a svaka vrsta na svoj način prima udarac.
// Napišite baznu klasu Enemy koja ima ime i zdravlje. Njezina virtualna metoda
// take_damage(d) smanji zdravlje za d, a virtualni destruktor ispiše da neprijatelj
// nestaje. Iz klase Enemy izvedite tri klase:
// ◦Goblin (zdravlje 20) prima udarac isto kao Enemy;
// ◦Bat (zdravlje 15) izbjegne svaki drugi udarac i tada ne gubi zdravlje;
// ◦Ghost (zdravlje 30) prima samo pola štete.

// 

class Enemy{
private: 
    std::string ime;
    int zdravlje;
public:

    Enemy(std::string im,int zdrav) : ime(im), zdravlje(zdrav){}
    virtual ~Enemy(){std::cout<<ime<<" nestaje"<<std::endl;}
    std::string get_ime() const { return ime; }
    int get_zdravlje() const { return zdravlje; }
    virtual void take_damage(int d){
        zdravlje-=d;
        if(zdravlje<0)
        zdravlje=0;
    }
};

class Goblin : public Enemy{
private:
   
public:
    Goblin() : Enemy("Goblin",20){}

};

class Bat : public Enemy{
private:
int defcounter=0;
public:
    Bat() : Enemy("Bat",15) {}
    void take_damage(int d) override {
        if(defcounter%2==0){
            Enemy::take_damage(d);
        }
        else{
            std::cout<<"Bat izbjegne udarac"<<std::endl;
        }
        defcounter++;

    }
};

class Ghost : public Enemy{

public:
    Ghost() : Enemy("Ghost",30){}

    void take_damage(int d) override{
        Enemy::take_damage(d/2);
    }
};

// Klasa Level čuva neprijatelje u std::vector<Enemy*> i vlasnik je svih neprijate-
// lja u levelu: neprijatelji se stvaraju s new, a Level ih briše u svom destruktoru.
// Kopiranje levela zabranite. Kad u levelu eksplodira bomba, metoda explode(d)
// svakom neprijatelju zada udarac d, a svaki ga neprijatelj primi na svoj način.
// Mrtvi neprijatelji se zatim brišu i uklanjaju iz levela. Ostale metode klase Level
// vide se iz programa level_main.cpp.


class Level{
private:
    std::vector<Enemy*> lista;
public:
    Level () {}
    Level (const Level& other) = delete;
    Level& operator=(const Level& other)=delete;
    ~Level () {
        for(auto &i : lista){
            delete i;
        }
    }

    void add(Enemy* novi){
        lista.push_back(novi);
    }

    size_t size()const{return lista.size();}


    void explode(int dmg){
        for(auto i : lista){
            i->take_damage(dmg);
        }
    }

    void print(){
        for(auto i : lista){
            std::cout<<i->get_ime()<<" "<<i->get_zdravlje()<<std::endl;
        }
    }

    void remove_dead(){
        std::vector<Enemy*> ziv;
        for(auto i : lista){
            if(i->get_zdravlje()==0){
                delete i;
            }
            else
                ziv.push_back(i);
        }
        lista=ziv;
    }

};

int main()
{
    Level cave;
    cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
    cave.add(new Bat);
    cave.add(new Ghost);
    cave.add(new Goblin);
    std::cout << cave.size() << '\n';

    cave.explode(10);                // bomba pogodi sve neprijatelje
    cave.print();
    std::cout << "---\n";
    cave.explode(10);
    cave.print();
    std::cout << "---\n";
    cave.remove_dead();
    std::cout << cave.size() << '\n';
    std::cout << "--- kraj ---\n";
    return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

    4
    Goblin 10
    Bat 5
    Ghost 25
    Goblin 10
    ---
    Bat izbjegne udarac
    Goblin 0
    Bat 5
    Ghost 20
    Goblin 0
    ---
    Goblin nestaje
    Goblin nestaje
    2
    --- kraj ---
    Bat nestaje
    Ghost nestaje
*/

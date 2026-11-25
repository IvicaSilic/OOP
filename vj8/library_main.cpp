// Vjezba 8, zadatak 4: napisite klase Item, Book, Film, Member i Library iznad main.

#include <iostream>
#include <string>
#include <vector>


// . Knjižnica posuđuje knjige i filmove. Napišite baznu klasu Item koja ima naslov i
// virtualnu metodu za ispis. Iz nje izvedite dvije klase:
// ◦Book ima i autora, kojeg ispiše u zagradama;
// ◦Film ima i trajanje u minutama, koje ispiše u uglatim zagradama.
// Primjerci su objekti u funkciji main. Knjižnica (Library) i član (Member) pamte
// samo pointere na njih (std::vector<Item*>), pa nisu njihovi vlasnici i ne brišu
// ih.
// ◦Primjerak je uvijek ili u knjižnici ili kod člana, pa posudba i vraćanje premje-
// štaju pointer iz jednog vektora u drugi.
// ◦Ako primjerka koji se posuđuje nema, posudba vrati false.
// Program za testiranje je library_main.cpp.
// Tko je vlasnik primjeraka? Što bi se dogodilo kad bi Library u destruktoru napravila delete?
// ovdje napisite klase

class Item{
private:
    std::string naslov;
public:
    Item(){};
    virtual ~Item(){}
    virtual void print();
};


int main()
{
    Book dune("Dina", "Frank Herbert");
    Film dune_film("Dina", 155);
    Book odyssey("2001: Odiseja u svemiru", "Arthur C. Clarke");

    Library lib;
    lib.add(&dune);
    lib.add(&dune_film);
    lib.add(&odyssey);
    lib.print();

    Member ana("Ana");
    lib.lend(1, ana);
    std::cout << lib.lend(5, ana) << '\n';
    lib.print();
    ana.print();

    lib.take_back(ana, 0);
    lib.print();
    ana.print();
    return 0;
}

/*
Ocekivani ispis:

    knjiznica: Dina (Frank Herbert) Dina [155 min] 2001: Odiseja u svemiru (Arthur C. Clarke)
    0
    knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke)
    Ana: Dina [155 min]
    knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke) Dina [155 min]
    Ana:
*/

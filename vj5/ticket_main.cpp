// Vježba 5, zadatak 5
// Napišite klasu Ticket (ulaznica za koncert) s nazivom koncerta i jedinstvenim brojem.
// - Broj se dodjeljuje automatski u konstruktoru: prva ulaznica ima broj 1, sljedeća 2,
//   itd. Koristite statički član (definicija izvan klase).
// - Statička metoda issued() vraća broj dosad izdanih ulaznica.

#include <iostream>
#include <string>

class Ticket {
    std::string concert;
    int id;
    static int issued_count;

public:
    Ticket(const std::string& c) : concert(c), id(++issued_count) {}
    int get_id() const { return id; }
    static int issued() { return issued_count; }
};

int Ticket::issued_count = 0;   

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/

// Vježba 5, zadatak 6
// Napišite klasu Coin (novčić u igri) s vrijednošću i statičkim brojačem novčića koji trenutno
// postoje. Novčić postoji dok ga igrač ne pokupi.
// - Konstruktor povećava brojač, a destruktor ga smanjuje.
// - Statička metoda remaining() vraća broj novčića koji trenutno postoje.
// Za razliku od Ticket, koji broji koliko je ulaznica izdano, ovdje se broje novčići koji još
// postoje.

#include <iostream>

class Coin {
    int value;
    static int existing;   

public:
    explicit Coin(int v) : value(v) { ++existing; }

    Coin(const Coin&) = delete;   

    ~Coin() { --existing; }

    static int remaining() { return existing; }
};

int Coin::existing = 0;

void bonus()              
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}

int main()
{
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    3
    1
    4
    1
*/

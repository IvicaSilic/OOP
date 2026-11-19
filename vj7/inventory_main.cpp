// Vjezba 7, zadatak 4: napisite klasu Inventory iznad funkcije show.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klasu Inventory
class Inventory {
private:
    std::vector<std::string> predmeti;
    std::size_t max;

public:
    Inventory(std::size_t max) : max(max) {}

    Inventory& operator+=(const std::string& predmet) {
        if (predmeti.size() < max)
            predmeti.push_back(predmet);
        return *this;
    }

    std::string& operator[](std::size_t i) {
        return predmeti[i];
    }

    const std::string& operator[](std::size_t i) const {
        return predmeti[i];
    }

    std::size_t size() const {
        return predmeti.size();
    }

    explicit operator bool() const {
        return !predmeti.empty();
    }
};

void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/

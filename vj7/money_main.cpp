// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.
// Napišite klasu Money za iznos u eurima. Iznos se čuva kao cijeli broj centi (int), da
// se izbjegnu greške zaokruživanja s double. Konstruktor Money(int euros = 0, int
// cents = 0).
// ◦+= i +; < za uspoređivanje iznosa.
// ◦<< ispisuje iznos u obliku 12.50 EUR; centi se uvijek ispisuju s dvije znamenke (1.05,
// ne 1.5).
// ◦>> čita iznos u obliku 12.50: cijeli broj, znak, cijeli broj. Ako znak nije točka,
// operator sam postavlja failbit: in.setstate(std::ios::failbit).
// Datoteka racun.txt u svakom retku ima naziv stavke i cijenu. Program za testiranje u
// datoteci money_main.cpp čita stavke dok čitanje uspijeva i ispisuje broj stavki, ukupni
// iznos i najskuplju stavku (očekivani ispis je na dnu datoteke). Jedan redak u datoteci je
// neispravan.


#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

// ovdje napisite klasu Money i operatore
class Money{
public:
    Money(int eur = 0, int cce = 0) : cents(eur * 100 + cce) {}

    Money& operator+=(const Money& other)
    {
        cents += other.cents;
        return *this;
    }

    int getCents() const { return cents; }

private:
    int cents;
};

Money operator+(Money a, const Money& b)
{
    return a += b;
}

bool operator<(const Money& a, const Money& b)
{
    return a.getCents() < b.getCents();
}

std::ostream& operator<<(std::ostream& out, const Money& m)
{
    return out << m.getCents() / 100 << '.'
               << std::setw(2) << std::setfill('0') << m.getCents() % 100
               << std::setfill(' ') << " EUR";
}

std::istream& operator>>(std::istream& in, Money& m)
{
    int euros, cents;
    char dot;
    if (in >> euros >> dot >> cents) {
        if (dot == '.')
            m = Money(euros, cents);
        else
            in.setstate(std::ios::failbit);
    }
    return in;
}
int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/

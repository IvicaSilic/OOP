// Vježba 5, zadatak 4
// Igra se sastoji od jednog igrača i jednog levela. Level ima barem jednog neprijatelja, a
// može imati i oružja. Igrač u svakom trenutku zna u kojem je levelu i može nositi najviše
// jedno oružje. Kad igrač podigne oružje, ono se uklanja iz levela i pripada igraču.
// - Nacrtajte dijagram klasa (Game, Player, Level, Enemy, Weapon) s vezama i multiplicitetima.
//   Za svaku vezu odlučite je li kompozicija ili asocijacija. Dijagram se može nacrtati na
//   papiru ili napisati kao tekst u PlantUML-u.
// - Dopunite kostur klasa u mapi igra: za svaku klasu postoje .h i .cpp datoteka s potrebnim
//   #include-ima. Napišite data membere, konstruktore i metode koje su već deklarirane u
//   kosturu. Iz koda mora biti vidljivo koja je veza kompozicija, a koja asocijacija.
// - Oružje igrača (najviše jedno) nacrtajte u dijagramu, ali ga u kodu ne pišite: data member
//   uvijek postoji, pa ne može izraziti "nula ili jedno oružje".
// - Sve datoteke prevode se zajedno: g++ -Wall -Wextra *.cpp -o igra. U Visual Studiju sve
//   datoteke treba dodati u isti projekt.
// Program za testiranje je u datoteci main.cpp (očekivani ispis je na dnu datoteke).

#include "Game.h"

int main()
{
    Game game("Labirint", "Ana");
    game.print();
    return 0;
}

/*
Ocekivani ispis:

    Labirint
    Igrac: Ana
    Level: neprijatelja 1, oruzja 0
*/

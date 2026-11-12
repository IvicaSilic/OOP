// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.
// Napomena za sve zadatke: data memberi su private. Osim navedenih metoda, klase smiju
// imati i dodatne: get metode za čitanje članova, pomoćne privatne metode i set metode koje
// čuvaju invarijantu klase (npr. provjerom ili ograničavanjem vrijednosti).

// 1. Napišite klasu IntStack: stog cijelih brojeva koji elemente čuva u nizu na heapu.
// ◦ Članovi: pointer na niz, broj elemenata i veličina niza (kapacitet). Konstruktor
// prima početni kapacitet (zadano 2) i zauzima niz s new[]; destruktor ga oslobađa.

// ◦ push(int x): ako je niz pun, zauzmite novi niz dvostruke veličine, prepišite elemente, oslobodite stari niz i tek onda dodajte x.

// ◦ pop(), top(), empty(), size() i capacity(). capacity() vraća veličinu niza

// ◦ Napišite copy konstruktor (deep copy).

// Program za testiranje je u datoteci intstack_main.cpp.
// Što bi se ispisalo bez vlastitog copy konstruktora?
#include <iostream>

// ovdje napisite klasu IntStack
class IntStack {
private:
    int* niz;
    int velicina;   
    int kapacitet; 

public:
    IntStack(int ka = 2): niz(new int[ka]), velicina(0), kapacitet(ka) {}
    ~IntStack() {delete[] niz;}
    //Bez vlastitog copy constructora bi se napravila plitku kopiju oboje bi pokazivali na istu memoriju
    IntStack(const IntStack& novi) : velicina(novi.velicina), kapacitet(novi.kapacitet) {
    niz = new int[kapacitet];
    for (int i = 0; i < velicina; i++) {
        niz[i] = novi.niz[i];
    }
}

    void push(int x){
        if (velicina >= kapacitet) {
            kapacitet *= 2;

            int* novi = new int[kapacitet];

            for (int i = 0; i < velicina; i++) {
                novi[i] = niz[i];
            }

            delete[] niz;
            niz = novi;
        }
    niz[velicina] = x;
    velicina++;
    }

    void pop() {
    if (velicina == 0) return;

    int* novi = new int[velicina - 1];

    for (int i = 0; i < velicina - 1; i++) {
        novi[i] = niz[i];
    }

    delete[] niz;
    niz = novi;
    velicina--;
    kapacitet = velicina;
    }

    int top(){
        return niz[velicina-1];
    }

    bool empty(){
        return velicina==0;
    }

    int size(){
        return velicina;
    }

    int capacity(){
        return kapacitet;
    }

};


int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    5 8 50
    50 99
    50 40 30 20 10
*/

// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>

// ovdje napisite klasu IntStack
class IntStack {
private:
    int* niz;
    int velicina;
    int kapacitet;

public:
    IntStack(int ka = 2): niz(new int[ka]), velicina(0), kapacitet(ka) {}
    ~IntStack() {delete[] niz;}

    IntStack(const IntStack& novi) : velicina(novi.velicina), kapacitet(novi.kapacitet) {
        std::cout << "copy konstruktor\n";
        niz = new int[kapacitet];
        for (int i = 0; i < velicina; i++) {
            niz[i] = novi.niz[i];
        }
    }

    IntStack& operator=(const IntStack& drugi) {
        std::cout << "copy assignment\n";
        if (this == &drugi) return *this;

        int* novi = new int[drugi.kapacitet];
        for (int i = 0; i < drugi.velicina; i++) {
            novi[i] = drugi.niz[i];
        }

        delete[] niz;
        niz = novi;
        velicina = drugi.velicina;
        kapacitet = drugi.kapacitet;
        return *this;
    }

    IntStack(IntStack&& drugi) : niz(drugi.niz), velicina(drugi.velicina), kapacitet(drugi.kapacitet) {
        std::cout << "move konstruktor\n";
        drugi.niz = nullptr;
        drugi.velicina = 0;
        drugi.kapacitet = 0;
    }

    IntStack& operator=(IntStack&& drugi) {
        std::cout << "move assignment\n";
        if (this == &drugi) return *this;

        delete[] niz;
        niz = drugi.niz;
        velicina = drugi.velicina;
        kapacitet = drugi.kapacitet;

        drugi.niz = nullptr;
        drugi.velicina = 0;
        drugi.kapacitet = 0;
        return *this;
    }

    void push(int x){
        if (velicina >= kapacitet) {
            kapacitet = kapacitet == 0 ? 2 : kapacitet * 2;

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
        velicina--;
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
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/

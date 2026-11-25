// Vjezba 8, zadatak 1: prije pokretanja napisite sto ce program ispisati.

#include <iostream>

struct Member {
    Member() { std::cout << "M "; }
    ~Member() { std::cout << "~M "; }
};

struct Base {
    Base() { std::cout << "B "; }
    ~Base() { std::cout << "~B "; }
    void hello() const { std::cout << "Base::hello\n"; }
    virtual void greet() const { std::cout << "Base::greet\n"; }
};

struct Derived : public Base {
    Member m;
    Derived() { std::cout << "D\n"; }
    ~Derived() { std::cout << "~D "; }
    void hello() const { std::cout << "Derived::hello\n"; }
    void greet() const override { std::cout << "Derived::greet\n"; }
};

int main()
{
    {
        Derived d;
        d.hello();
        d.greet();
        Base& r = d;
        r.hello();
        r.greet();
    }
    std::cout << '\n';

    Base* p = new Derived;
    p->greet();
    delete p;
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    B M D
    Derived::hello
    Derived::greet
    Base::hello
    Derived::greet
    ~D ~M ~B
    B M D
    Derived::greet
    ~B

Nakon dodavanja virtual ispred ~Base() zadnji redak je:

    ~D ~M ~B
*/

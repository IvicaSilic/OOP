    // Vjezba 8, zadatak 5: napisite klase Account, SavingsAccount i CurrentAccount iznad funkcija.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase
// 5. Napišite klasu Account za bankovni račun koji ima vlasnika i stanje. Stanje
// je privatno i mijenja se samo preko protected metode change(amount), koja
// stanju doda amount. Virtualna metoda za podizanje novca (withdraw) ne uspije
// ako bi stanje otišlo u minus. Virtualna metoda month_end() poziva se na kraju
// mjeseca i za običan račun ne radi ništa. Iz klase Account izvedite dvije klase:
// ◦SavingsAccount (štedni račun) ima kamatnu stopu i na kraju mjeseca doda
// kamatu;
// ◦CurrentAccount (tekući račun) dopušta minus do zadane granice.
// Program za testiranje je account_main.cpp.
// Funkcije end_by_value i end_by_ref napisane su u programu za testiranje. Zašto end_by_value
// ne doda kamatu, a end_by_ref doda?

class Account{
private:
    std::string vlasnik;
    int stanje;
protected:
    void change(int ammount){stanje+=ammount;}
public:
    Account(std::string vl,int sta) : vlasnik(vl),stanje(sta) {}
    virtual ~Account(){}

    virtual bool withdraw(int amount){
        if(stanje-amount>=0){
            change(-amount);
            return true;
        }
        return false;
    }
    virtual void month_end(){}
    int get_money(){return stanje;}

    virtual void print(){
        std::cout<<vlasnik<<": "<<stanje<<std::endl;
    }
};

// ◦CurrentAccount (tekući račun) dopušta minus do zadane granice.
class CurrentAccount : public Account{
private:
    int dopusteni_minus;
public:
    CurrentAccount (std::string na,int val,int dop) : Account(na,val), dopusteni_minus(dop) {}
    bool withdraw(int amount) override {
        if(get_money()-amount>=-dopusteni_minus){
            change(-amount);
            return true;
        }
        return false;
    }
};



// ◦SavingsAccount (štedni račun) ima kamatnu stopu i na kraju mjeseca doda
// kamatu;
class SavingsAccount : public Account{
private:
    double kamatna_stopa;
public:
    SavingsAccount (std::string im,int sta,double kam) : Account(im,sta), kamatna_stopa(kam){}

    bool withdraw(int amount) override{
       return  Account::withdraw(amount);
    }
    void month_end() override{
        Account::change((get_money()*kamatna_stopa));
    }
};



void end_by_value(Account a) { a.month_end(); }
void end_by_ref(Account& a) { a.month_end(); }


int main()
{
    // SavingsAccount: vlasnik, pocetno stanje, kamatna stopa
    SavingsAccount ana("Ana", 1000, 0.01);
    // CurrentAccount: vlasnik, pocetno stanje, dopusteni minus
    CurrentAccount marko("Marko", 100, 500);

    std::vector<Account*> accounts = {&ana, &marko};

    for (Account* a : accounts)
        std::cout << a->withdraw(300) << ' ';
    std::cout << '\n';
    for (Account* a : accounts)
        a->print();

    end_by_value(ana);
    ana.print();
    end_by_ref(ana);
    ana.print();
    return 0;
}

/*
Ocekivani ispis:

    1 1
    Ana: 700
    Marko: -200
    Ana: 700
    Ana: 707
*/

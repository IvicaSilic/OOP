// Proširite klasu Ticket iz prošle vježbe.

// ◦ Napišite Ticket t4 = t1; i ispišite brojeve obiju ulaznica. Zašto rezultat nije ispravan?
    //Imaju iste brojeve jer nije napisan copy konstruktor oni ce samo pokazivat na situ vrijednost u memoriji. 


// ◦ Ulaznica se ne smije duplicirati: zabranite kopiranje (= delete za copy konstruktor). Provjerite da se Ticket t4 = t1; više ne prevodi.
// ◦ Napišite funkciju void print(const Ticket& t) i pozovite je s print(t1). Zatim
// promijenite parametar u Ticket t. Zašto se poziv više ne prevodi?
    //Zato jer c++ automatski asocira poziv sa Ticket t sa copy konstruktorom

#include<iostream>
#include<string>

class Ticket{
private:    
    std::string concertName;
    int id;
    static int number_tickets;
public:
    Ticket(std::string prva) : concertName(prva), id(number_tickets+1) {number_tickets++;}
    Ticket(Ticket& novi) = delete;

    int get_id(){ return id;}
    std::string get_Name() const {return concertName;}
    
    static int issued(){ return number_tickets;}
};

void print(Ticket &t){
        std::cout<<t.get_id();
    }



int Ticket::number_tickets=0;


int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';

    //Ticket t4=t1;
    //std::cout<<t4.get_id()<<" "<<t1.get_id();
    print(t1);
    return 0;
};

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/

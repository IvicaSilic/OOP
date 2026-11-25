// Vjezba 8, zadatak 6: u programu je 6 gresaka. Tri javlja kompajler, a tri se vide tek u ispisu.
// Ispravite ih tako da program ispise ocekivani ispis s dna datoteke.

#include <iostream>
#include <string>
#include <vector>

class Notification {
protected: //dodan protected da ga izvedbene klase mogu vidjeti
    std::string recipient;
public:
    Notification(const std::string& r) : recipient(r) {}
    virtual ~Notification() { std::cout << "~Notification\n"; }  ///Virtual destruktro treba biti.
    virtual void send() const { std::cout << "obavijest za " << recipient << '\n'; }    //virtual send treba biti.
};

class Email : public Notification {
    std::string subject;
public:
    Email(const std::string& r, const std::string& s) : Notification(r), subject(s) {} //Vamo je falilo Notification(r)
    ~Email() { std::cout << "~Email\n"; }
    void send() const override { std::cout << "email za " << recipient << ": " << subject << '\n'; } //faliu override
};

class Sms : public Notification { //fali public
    std::string text;
public:
    Sms(const std::string& r, const std::string& t) : Notification(r), text(t) {}
    void send() const override { std::cout << "SMS za " << recipient << ": " << text << '\n'; } //fali override
};

void send_twice(Notification& n) //po vrijednosti nastala kopija tipa Notification
{
    n.send();
    n.send();
}


// Zašto kompajler ne može otkriti zadnje tri greške? Kako bi override pomogao da se barem jedna
// od njih otkrije ranije?

//Jer nisu greske kod radi samo sta je krivo napisan za rezultat koji mi zelimo
//send marked override, but does not override dobili bi tu gresku
//berz override compiler gleda to kao novu metodu, iskompajlira i onda zove bazni send i neradi nakon toga
//sad overrride izbaci does not override

int main()
{
    std::vector<Notification*> inbox;
    inbox.push_back(new Email("Ana", "Kolokvij u petak"));
    inbox.push_back(new Sms("Marko", "Kasnim 10 min"));

    for (Notification* n : inbox)
        n->send();
    std::cout << "---\n";
    send_twice(*inbox[1]);
    std::cout << "---\n";

    for (Notification* n : inbox)
        delete n;
    return 0;
}

/*
Ocekivani ispis:

    email za Ana: Kolokvij u petak
    SMS za Marko: Kasnim 10 min
    ---
    SMS za Marko: Kasnim 10 min
    SMS za Marko: Kasnim 10 min
    ---
    ~Email
    ~Notification
    ~Notification
*/

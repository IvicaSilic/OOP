// Vjezba 8, zadatak 3: napisite klase Vehicle, Car i Truck iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase
// 3. Vozila troše gorivo, a potrošnja ovisi o vrsti vozila. Napišite klasu Vehicle
// koja pamti ime, prijeđene kilometre i osnovnu potrošnju u litrama na 100 km.
// Virtualna metoda consumption() vraća potrošnju. Metoda fuel() nije virtualna
// i računa ukupnu potrošnju u litrama: kilometri ·consumption() / 100. Budući
// da poziva virtualnu metodu consumption(), svako vozilo računa sa svojom po-
// trošnjom. Iz klase Vehicle izvedite dvije klase:
// ◦Car može voziti u eco načinu, u kojem troši 80 % osnovne potrošnje;
// ◦Truck vozi teret i troši 2 litre više po svakoj toni tereta, a nakon ispisa
// iz klase Vehicle dopiše teret.
// U izvedenim klasama pozovite bazne verzije metoda umjesto da ponovno pišete
// isti koˆd. Program za testiranje je vehicle_main.cpp.
// Zašto fuel() ne mora biti virtualna, a ipak svako vozilo računa sa svojom potrošnjom?

class Vehicle{
private:
    std::string name;
    double kilometri;
    double potrosnja;
public:
    Vehicle(std::string nam,double fu,double avg) : name(nam),kilometri(fu),potrosnja(avg){}
    virtual ~Vehicle() {}

    virtual double consumption() const {return potrosnja;}
    double fuel() const {return kilometri*consumption()/100;}
    virtual void print()const{std::cout<<name<<" "<<fuel()<<" l";}

};

class Car : public Vehicle{
private:
    bool ekonacin;
public:
    Car(std::string im,double km,double po,double eko) : Vehicle(im,km,po), ekonacin(eko){}
    double consumption() const override{
        if(ekonacin){
            return Vehicle::consumption()*0.8;
        }
        else{
            return Vehicle::consumption();
        }
    }

};

// ◦Truck vozi teret i troši 2 litre više po svakoj toni tereta, a nakon ispisa
// iz klase Vehicle dopiše teret.
class Truck : public Vehicle{
private:
    double teret;
public:
    Truck(std::string im,double km, double potr, double ter) : Vehicle(im, km, potr), teret(ter){}
    double consumption()const override{
        return Vehicle::consumption()+(2*teret);
    }
    void print()const override { 
        Vehicle::print();std::cout<<"(Teret "<<teret<<")";
    }
};


int main()
{
    // Car: ime, kilometri, osnovna potrosnja (l/100 km), eco nacin
    Car clio("Clio", 200, 6.0, false);
    Car yaris("Yaris", 200, 6.0, true);
    // Truck: ime, kilometri, osnovna potrosnja (l/100 km), teret u tonama
    Truck iveco("Iveco", 300, 20.0, 5);

    std::vector<Vehicle*> fleet = {&clio, &yaris, &iveco};

    double total = 0;
    for (Vehicle* v : fleet) {
        v->print();
        std::cout << '\n';
        total += v->fuel();
    }
    std::cout << "ukupno: " << total << " l\n";
    return 0;
}

/*
Ocekivani ispis:

    Clio: 12 l
    Yaris: 9.6 l
    Iveco: 90 l (teret 5 t)
    ukupno: 111.6 l
*/

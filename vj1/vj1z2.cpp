#include <iostream>
#include <string>

int main()
{
    int godina;
    std::cout << "Godina rodjenja: ";
    std::cin >> godina;
    std::cin.ignore(); 
    std::string ime;
    std::cout << "Ime i prezime: ";
    std::getline(std::cin, ime);

    std::string inicijali = "";
    bool pocetak_rijeci = true;
    for (char c : ime)
    {
        if (c == ' ')
        {
            pocetak_rijeci = true;
        }
        else if (pocetak_rijeci)
        {
            inicijali += c;
            inicijali += '.';
            pocetak_rijeci = false;
        }
    }

    int broj_znakova = 0;
    for (char c : ime)
    {
        if (c != ' ')
        {
            broj_znakova++;
        }
    }

    int tekuca_godina = 2026;
    int godine = tekuca_godina - godina;

    std::cout << "Inicijali: " << inicijali << std::endl;
    std::cout << "Broj znakova bez razmaka: " << broj_znakova << std::endl;
    std::cout << "Ove godine navrsava " << godine << " godina" << std::endl;

    return 0;
}

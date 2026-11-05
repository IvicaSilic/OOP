// Vježba 5, zadatak 2
// Klasa Clip predstavlja isječak pjesme od sekunde start do sekunde end. Zadana je u
// datoteci clip.cpp, zajedno s main (kod klase je ispod).
// Ispravite klasu tako da program ispiše:
//     Concrete (Shame): 180 s
// Za svaku grešku objasnite zašto nastaje.
// Hint 1: Dvije greške javlja kompajler. Pogledajte na predavanju koji članovi moraju dobiti
//         vrijednost pri nastanku i što znači this->.
// Hint 2: Treća greška nije greška pri kompajliranju: program se prevede, ali ispiše krivo
//         trajanje. g++ uz -Wall na nju upozori, a Visual Studio ne upozori ni na razini Level4
//         (/W4). Usporedite redoslijed članova u klasi s redoslijedom u inicijalizacijskoj listi.

#include <iostream>
#include <string>

// class Clip {
//     int length;
//     int start;
//     int end;
//     std::string name;
//     const int max_length;
// public:
//     Clip(const std::string& name, int s, int e)
//         : start(s), end(e), length(end - start)
//     {
//         name = name;
//         max_length = 600;
//     }
//     void print() const {
//         std::cout << name << ": " << length << " s\n";
//     }
// };


class Clip {
    int start;  
    int end;
    int length;
    std::string name;
    const int max_length;
public:

    Clip(const std::string& n, int s, int e)
        : start(s), end(e), length(end - start), name(n), max_length(600)
    {
        
    }
    void print() const {
        std::cout << name << ": " << length << " s\n";
    }
};

int main()
{
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}

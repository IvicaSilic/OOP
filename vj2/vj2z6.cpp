#include <iostream>
#include <string>

struct Student
{
    std::string ime;
    std::string jmbag;
    int godina;      
    int ects;        
    double prosjek;  
};

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&))
{
    for (int i = 0; i < n; i++)
    {
        if (cond(s[i]))
        {
            action(s[i]);
        }
    }
}

void ispisi(Student& s)
{
    std::cout << s.ime << " | " << s.jmbag << " | godina " << s.godina
              << " | ECTS " << s.ects << " | prosjek " << s.prosjek << std::endl;
}

void povecaj_godinu(Student& s)
{
    s.godina++;
}

int main()
{
    Student studenti[] = {
        {"Ana Anic", "0036500001", 1, 12, 4.2},
        {"Ivo Ivic", "0036500002", 1, 0, 2.8},
        {"Marta Martic", "0036500003", 2, 48, 3.9},
        {"Karlo Karlic", "0036500004", 3, 45, 3.1},
        {"Eugen Eugenic", "0036500005", 1, 6, 3.6},
    };
    int n = 5;


    std::cout << "Prva godina, barem jedan ispit:" << std::endl;
    filter_students(studenti, n, ispisi,
                    [](const Student& s) { return s.godina == 1 && s.ects > 0; });

    std::cout << "Prosjek veci od 3.5:" << std::endl;
    filter_students(studenti, n, ispisi,
                    [](const Student& s) { return s.prosjek > 3.5; });

    // barem 45 ECTS bodova: povecaj godinu
    filter_students(studenti, n, povecaj_godinu,
                    [](const Student& s) { return s.ects >= 45; });

    std::cout << "Nakon povecanja godine:" << std::endl;
    filter_students(studenti, n, ispisi,
                    [](const Student&) { return true; });

    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string jmbag;
    std::string surname;
    int points;
};

int main() {
    std::vector<Student> registered{
        {"0302", "Kovac", 78}, {"0117", "Babic", 45},
        {"0255", "Maric", 91}, {"0117", "Babic", 45},
        {"0410", "Novak", 78}, {"0089", "Juric", 62},
        {"0255", "Maric", 91}, {"0520", "Maric", 55},
        {"0333", "Peric", 30}};

    std::sort(registered.begin(), registered.end(),
              [](const Student& a, const Student& b) { return a.jmbag < b.jmbag; });
    registered.erase(std::unique(registered.begin(), registered.end(),
                                 [](const Student& a, const Student& b) { return a.jmbag == b.jmbag; }),
                     registered.end());
    std::cout << "prijavljenih: " << registered.size() << '\n';

    int prag;
    std::cout << "Prag: ";
    std::cin >> prag;
    registered.erase(std::remove_if(registered.begin(), registered.end(),
                                    [prag](const Student& s) { return s.points < prag; }),
                     registered.end());

    std::sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
        return a.points != b.points ? a.points > b.points : a.surname < b.surname;
    });
    for (std::size_t i = 0; i < registered.size(); ++i) {
        const Student& s = registered[i];
        std::cout << i + 1 << ". " << s.surname << " (" << s.jmbag << ") " << s.points << '\n';
    }
}

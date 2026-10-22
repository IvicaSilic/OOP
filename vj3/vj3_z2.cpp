#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Broj dana: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "Mora biti barem 1 dan.\n";
        return 0;
    }

    std::vector<double> t(n);
    for (std::size_t i = 0; i < t.size(); ++i)
        std::cin >> t[i];

    std::vector<double> promjene;
    promjene.reserve(n - 1);
    for (auto it = t.begin() + 1; it != t.end(); ++it)
        promjene.push_back(*it - *(it - 1));
    std::cout << "Promjene: ";
    for (double x : promjene)
        std::cout << x << ' ';
    std::cout << '\n';

    t.resize(7, t.back()); 
    std::cout << "Izvjestaj: ";
    for (double x : t)
        std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> a(5);
    std::vector<int> b{5};
    std::cout << "a(5): " << a.size() << " elemenata, b{5}: " << b.size()
              << " element (vrijednost " << b[0] << ")\n";
}

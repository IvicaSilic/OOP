#include <algorithm>
#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v) {
    int x;
    while (std::cin >> x && x != 0)
        v.push_back(x);
}

int main() {
    std::vector<int> v;
    std::cout << "Unesite brojeve (0 za kraj): ";
    input_vector(v);

    int k;
    std::cout << "k: ";
    std::cin >> k;
    if (k <= 0) {
        std::cout << "k mora biti veci od 0\n";
        return 0;
    }

    auto negativnih = std::count_if(v.begin(), v.end(), [](int x) { return x < 0; });
    std::cout << "negativnih: " << negativnih << '\n';

    auto visekratnik = [k](int x) { return x % k == 0; };
    auto it = std::find_if(v.begin(), v.end(), visekratnik);
    if (it == v.end())
        std::cout << "nema visekratnika od " << k << '\n';
    else
        std::cout << "prvi visekratnik od " << k << ": " << *it
                  << " (pozicija " << it - v.begin() << ")\n";

    if (v.empty()) {
        std::cout << "nema brojeva za min i max\n";
        return 0;
    }
    auto mn = std::min_element(v.begin(), v.end());
    auto mx = std::max_element(v.begin(), v.end());
    std::cout << "min " << *mn << " (pozicija " << mn - v.begin() << "), max " << *mx
              << " (pozicija " << mx - v.begin() << ")\n";

    v.erase(std::remove_if(v.begin(), v.end(), visekratnik), v.end());
    std::cout << "bez visekratnika:";
    for (int x : v)
        std::cout << ' ' << x;
    std::cout << '\n';
}

#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v) {
    int x;
    while (std::cin >> x && x != 0)
        v.push_back(x);
}

void print_vector(const std::vector<int>& v) {
    for (int x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}

void fill_and_report(std::vector<int>& v) {
    for (int i = 1; i <= 20; ++i) {
        v.push_back(i);
        std::cout << "size=" << v.size() << " capacity=" << v.capacity() << '\n';
    }
}

int main() {
    std::vector<int> v;
    std::cout << "Unesite cijele brojeve (0 za kraj): ";
    input_vector(v);
    std::cout << "Vektor: ";
    print_vector(v);
    std::cout << "Obrnuto: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';

    std::vector<int> prazan;
    fill_and_report(prazan);

    std::vector<int> rezerviran;
    rezerviran.reserve(100);
    fill_and_report(rezerviran);
    rezerviran.shrink_to_fit();
    std::cout << "Kapacitet nakon shrink_to_fit: " << rezerviran.capacity() << '\n';
}

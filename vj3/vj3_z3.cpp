#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours) {
    return std::accumulate(hours.begin(), hours.end(), 0.0);
}

int best_day(const std::array<double, DAYS>& hours) {
    return static_cast<int>(std::max_element(hours.begin(), hours.end()) - hours.begin()) + 1;
}

int main() {
    std::array<double, DAYS> prvi{}, drugi;
    std::cout << "Sati za " << DAYS << " dana: ";
    for (double& h : prvi)
        std::cin >> h;
    std::cout << "Ukupno sati: " << total(prvi) << '\n';
    std::cout << "Dan s najvise sati: " << best_day(prvi) << '\n';

    drugi.fill(1.5);
    std::cout << std::boolalpha;
    std::cout << "prvi == drugi: " << (prvi == drugi) << ", prvi < drugi: " << (prvi < drugi) << '\n';
    prvi.swap(drugi);
    std::cout << "Nakon swap: prvi=" << total(prvi) << " drugi=" << total(drugi) << '\n';
}

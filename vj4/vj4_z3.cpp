#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool starts_with(const std::string& s, const std::string& prefix) {
    return prefix.size() <= s.size() && std::equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix) {
    return suffix.size() <= s.size() && std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    std::vector<std::string> datoteke{"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md",
                                      "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    auto cpp_broj = std::count_if(datoteke.begin(), datoteke.end(),
                                  [](const std::string& d) { return ends_with(d, ".cpp"); });
    std::cout << ".cpp datoteka: " << cpp_broj << '\n';

    datoteke.erase(std::remove_if(datoteke.begin(), datoteke.end(),
                                  [](const std::string& d) { return starts_with(d, "vjezba"); }),
                   datoteke.end());
    for (const auto& d : datoteke)
        std::cout << d << ' ';
    std::cout << '\n';
}

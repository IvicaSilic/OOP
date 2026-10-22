#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> words;
    std::size_t start = 0;
    while (start < text.size()) {
        std::size_t end = text.find(' ', start);
        if (end == std::string::npos)
            end = text.size();
        if (end > start)
            words.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    return words;
}

int main() {
    std::vector<std::string> recnik{"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije",
                                    "jednostavan", "za", "pocetnike"};
    std::sort(recnik.begin(), recnik.end());

    std::string recenica;
    std::cout << "Recenica: ";
    std::getline(std::cin, recenica);

    std::vector<std::string> rijeci = split_words(recenica);
    for (auto& r : rijeci) {
        r.erase(std::remove_if(r.begin(), r.end(), [](char c) { return c == ',' || c == '.'; }), r.end());
        std::transform(r.begin(), r.end(), r.begin(),
                       [](char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c))); });
    }

    std::vector<std::string> nepoznate;
    for (const auto& r : rijeci)
        if (!std::binary_search(recnik.begin(), recnik.end(), r))
            nepoznate.push_back(r);

    std::cout << "nepoznatih rijeci: " << nepoznate.size();
    for (const auto& r : nepoznate)
        std::cout << ' ' << r;
    std::cout << '\n';
}

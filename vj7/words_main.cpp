#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct WordCount {
    std::string word;
    int count;
};

std::string clean(const std::string& word)
{
    std::string rez;
    for (char c : word) {
        if (std::isalpha(c))
            rez += std::tolower(c);
    }
    return rez;
}

int main()
{
    std::ifstream in("tekst.txt");
    if (!in) {
        std::cout << "Datoteka tekst.txt ne postoji\n";
        return 1;
    }

    std::map<std::string, int> freq;
    std::string rijec;
    while (in >> rijec) {
        std::string w = clean(rijec);
        if (w.empty())
            continue;
        ++freq[w];
    }

    std::cout << "razlicitih rijeci: " << freq.size() << '\n';
    std::cout << "alice: " << freq["alice"] << '\n';

    std::vector<WordCount> v;
    for (const auto& par : freq)
        v.push_back({par.first, par.second});

    std::sort(v.begin(), v.end(), [](const WordCount& a, const WordCount& b) {
        if (a.count != b.count)
            return a.count > b.count;
        return a.word < b.word;
    });

    for (std::size_t i = 0; i < 5 && i < v.size(); ++i)
        std::cout << v[i].word << ": " << v[i].count << '\n';

    return 0;
}

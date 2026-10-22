#include <algorithm>
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
    std::string text;
    std::cout << "Recenica: ";
    std::getline(std::cin, text);

    auto words = split_words(text);
    std::cout << "broj rijeci: " << words.size() << '\n';
    if (words.empty())
        return 0;

    std::string najdulja = words[0];
    for (const auto& w : words)
        if (w.size() > najdulja.size())
            najdulja = w;
    std::cout << "najdulja: " << najdulja << '\n';

    std::string obrnuto;
    for (std::size_t i = words.size(); i-- > 0;) {
        obrnuto += words[i];
        if (i > 0)
            obrnuto += '-';
    }
    std::cout << obrnuto << '\n';

    std::cout << "prva po abecedi: " << *std::min_element(words.begin(), words.end()) << '\n';
}

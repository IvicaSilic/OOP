#include <iostream>
#include <string>

std::string with_separators(std::string digits) {
    bool neg = !digits.empty() && digits[0] == '-';
    if (neg)
        digits.erase(0, 1);
    
    for (int i = static_cast<int>(digits.size()) - 3; i > 0; i -= 3)
        digits.insert(i, ".");
    return neg ? "-" + digits : digits;
}

std::string without_separators(std::string text) {
    std::size_t pos;
    while ((pos = text.find('.')) != std::string::npos)
        text.erase(pos, 1);
    return text;
}

int main() {
    std::string broj;
    std::cout << "Broj: ";
    std::cin >> broj;
    std::string s = with_separators(broj);
    std::cout << s << '\n';
    std::cout << without_separators(s) << '\n';
}

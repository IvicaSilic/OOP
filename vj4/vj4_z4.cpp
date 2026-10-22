#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const std::string& password) {
    PasswordInfo info{};
    info.length = static_cast<int>(password.size());
    info.digits = std::count_if(password.begin(), password.end(),
                                [](char c) { return std::isdigit(static_cast<unsigned char>(c)); });
    info.uppercase = std::count_if(password.begin(), password.end(),
                                   [](char c) { return std::isupper(static_cast<unsigned char>(c)); });
    info.special = std::count_if(password.begin(), password.end(),
                                 [](char c) { return std::ispunct(static_cast<unsigned char>(c)); });
    return info;
}

bool is_strong(const PasswordInfo& info) {
    return info.length >= 10 && info.digits > 0 && info.uppercase > 0 && info.special > 0;
}

int main() {
    std::string password;
    std::cout << "Lozinka: ";
    std::cin >> password;

    PasswordInfo info = analyze(password);
    std::cout << "duljina " << info.length << ", znamenke " << info.digits
              << ", velika " << info.uppercase << ", posebni " << info.special << " -> "
              << (is_strong(info) ? "jaka" : "slaba") << '\n';
}

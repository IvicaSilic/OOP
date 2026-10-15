#include <iostream>

int main()
{
    int a{};
    int b{};
    std::cout << "Unesi dva cijela broja: ";
    std::cin >> a >> b;

    int zbroj{a + b};
    double sredina{(a + b) / 2.0};
    bool manji{a < b};

    std::cout << "Zbroj: " << zbroj << std::endl;
    std::cout << "Aritmeticka sredina: " << sredina << std::endl;
    std::cout << "a < b: " << manji << std::endl;

    return 0;
}

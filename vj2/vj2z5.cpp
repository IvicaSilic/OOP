#include <iostream>

inline double add(double a, double b)
{
    return a + b;
}

inline double subtract(double a, double b)
{
    return a - b;
}

inline double multiply(double a, double b)
{
    return a * b;
}

inline double divide(double a, double b)
{
    return a / b;
}

int main()
{
    double (*operacije[4])(double, double) = {add, subtract, multiply, divide};

    double a = 0;
    double b = 0;
    int op = 0;

    std::cout << "Unesi dva broja: ";
    std::cin >> a >> b;
    std::cout << "Operacija (0 zbroj, 1 razlika, 2 umnozak, 3 kvocijent): ";
    std::cin >> op;

    if (op < 0 || op > 3)
    {
        std::cout << "Nepostojeca operacija" << std::endl;
        return 1;
    }

    if (op == 3 && b == 0)
    {
        std::cout << "Dijeljenje s nulom nije moguce" << std::endl;
        return 1;
    }

    std::cout << "Rezultat: " << operacije[op](a, b) << std::endl;

    return 0;
}

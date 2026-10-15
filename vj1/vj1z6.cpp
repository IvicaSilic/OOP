#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;

    void reduce()
    {
        int a = numerator;
        int b = denominator;
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }

        if (a != 0)
        {
            numerator = numerator / a;
            denominator = denominator / a;
        }
    }

    double value()
    {
        return (double)numerator / denominator;
    }

    void print()
    {
        std::cout << numerator << "/" << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b)
{
    Fraction r;
    r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    r.denominator = a.denominator * b.denominator;
    r.reduce();
    return r;
}

int main()
{
    Fraction f1;
    f1.numerator = 6;
    f1.denominator = 8;
    Fraction f2;
    f2.numerator = 1;
    f2.denominator = 4;

    std::cout << "f1 prije reduce: ";
    f1.print();
    std::cout << std::endl;

    f1.reduce();
    std::cout << "f1 nakon reduce: ";
    f1.print();
    std::cout << ", decimalno: " << f1.value() << std::endl;

    Fraction zbir = sum(f1, f2);
    std::cout << "f1 + f2 = ";
    zbir.print();
    std::cout << std::endl;

    return 0;
}

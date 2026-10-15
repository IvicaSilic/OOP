#include <iostream>

namespace geo
{
    const double PI = 3.14;

    double area(double r)
    {
        return PI * r * r;
    }

    double area(double a, double b)
    {
        return a * b;
    }

    int area(int a)
    {
        return a * a;
    }

    void print_line(char c = '-', int length = 30)
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

int main()
{
    
    geo::print_line();
    std::cout << "area(5) = " << geo::area(5) << std::endl;
    std::cout << "area(5.0) = " << geo::area(5.0) << std::endl;
    std::cout << "area(2, 3) = " << geo::area(2, 3) << std::endl;
    std::cout << "area('A') = " << geo::area('A') << std::endl;
    geo::print_line('*', 10);

    return 0;
}

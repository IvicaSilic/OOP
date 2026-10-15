#include <iostream>
#include <string>


#define MAX(a, b) (((a) > (b)) ? (a) : (b))

template <typename T>
inline T my_max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    // Predvidanje za nepopravljeni makro (#define MAX(a, b) a > b ? a : b): a = 5, b = 3, c = 6
    // Zato sto se makro zamijeni tekstom: 2 * 3 > 5 ? 3 : 5 i 3 > 5 ? 3 : 5 + 1
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

    int i = 3;
    int m1 = MAX(++i, 2);
    std::cout << "MAX(++i, 2) = " << m1 << ", i = " << i << std::endl;

    i = 3;
    int m2 = my_max(++i, 2);
    std::cout << "my_max(++i, 2) = " << m2 << ", i = " << i << std::endl;

    std::cout << "my_max int: " << my_max(3, 5) << std::endl;
    std::cout << "my_max double: " << my_max(2.5, 1.5) << std::endl;
    std::cout << "my_max char: " << my_max('a', 'z') << std::endl;
    std::cout << "my_max string: " << my_max(std::string("Ana"), std::string("Ivo")) << std::endl;

    return 0;
}

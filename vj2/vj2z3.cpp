#include <iostream>

template <typename T>
inline bool ascending(T a, T b)
{
    return a < b;
}

template <typename T>
inline bool descending(T a, T b)
{
    return a > b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void print_array(const T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int ints[] = {5, 2, 9, 1, 7};
    double doubles[] = {2.5, -1.0, 3.75, 0.5};
    char chars[] = {'d', 'a', 'c', 'b'};

    my_sort(ints, 5, ascending<int>);
    std::cout << "int uzlazno: ";
    print_array(ints, 5);

    my_sort(doubles, 4, descending<double>);
    std::cout << "double silazno: ";
    print_array(doubles, 4);

    my_sort(chars, 4, ascending<char>);
    std::cout << "char uzlazno: ";
    print_array(chars, 4);

    // Zasto se poziv s ascending iz prethodnog zadatka ne prevodi?
    // Stara ascending(int, int) nije sablona, pa je ne mozemo pretvoriti u bool(*)(double, double)

    return 0;
}

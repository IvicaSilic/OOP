#include <iostream>

inline bool ascending(int a, int b)
{
    return a < b;
}

inline bool descending(int a, int b)
{
    return a > b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int niz[] = {5, 2, 9, 1, 7};
    int n = 5;

    my_sort(niz, n, ascending);
    std::cout << "Uzlazno: ";
    print_array(niz, n);

    my_sort(niz, n, descending);
    std::cout << "Silazno: ";
    print_array(niz, n);

    return 0;
}

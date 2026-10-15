#include <iostream>

int& find_max(int arr[], int n)
{
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max_index])
        {
            max_index = i;
        }
    }
    return arr[max_index];
}

int main()
{
    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n = 6;

    std::cout << "Niz: ";
    for (int x : numbers)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] < 0)
        {
            numbers[i] = -numbers[i];
        }
    }

    std::cout << "Apsolutne vrijednosti: ";
    for (int x : numbers)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // najveci element postavljamo na 0
    find_max(numbers, n) = 0;

    std::cout << "Nakon postavljanja maksimuma na 0: ";
    for (int x : numbers)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}

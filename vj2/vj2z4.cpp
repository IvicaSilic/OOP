#include <iostream>

void my_transform(int arr[], int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = f(arr[i]);
    }
}

int twice(int x)
{
    return x * 2;
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    my_transform(arr, n, twice);
    std::cout << "Udvostruceno: ";
    print_array(arr, n);

    my_transform(arr, n, [](int x) { return x % 2 == 0 ? x / 2 : x * 2; });
    std::cout << "Parni /2, neparni *2: ";
    print_array(arr, n);

    int suma = 0;
    int produkt = 1;
    auto zbroji_i_pomnozi = [&](int x) { suma += x; produkt *= x; };
    for (int i = 0; i < n; i++)
    {
        zbroji_i_pomnozi(arr[i]);
    }
    std::cout << "Suma: " << suma << ", produkt: " << produkt << std::endl;

    int prag = 5;
    int s = 0;
    auto zbroj_iznad_praga = [prag, &s](int x) { if (x > prag) s += x; };
    for (int i = 0; i < n; i++)
    {
        zbroj_iznad_praga(arr[i]);
    }
    std::cout << "Suma clanova vecih od " << prag << ": " << s << std::endl;

    // Moze li se lambda s kontekstom predati my_transform?
    // Ne: my_transform prima obican pokazivac na funkciju, a lambda s hvatanjem
    // je objekt koji nosi vrijednosti (prag), pa se ne moze pretvoriti u pokazivac.
    // my_transform(arr, n, [prag](int x) { return x + prag; });

    return 0;
}

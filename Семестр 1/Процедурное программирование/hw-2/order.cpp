#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

template <typename T>
T input(string message)
{
    cout << message << ": ";
    T value{};
    cin >> value;
    return value;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    auto N = input<double>("Введите число N");

    for (int i = 0; i < 10; i++)
    {
        if (N + i == 0) // skip 0 because it's not a natural number
        {
            printf("%2d. err\n", i + 1);
            continue;
        }
        if (N + i < 0)
        {
            printf("%2d. err\n", i + 1);
            continue;
        }
        printf("%2d. %g\n", i + 1, N + i);
    }
}

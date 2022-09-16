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

    auto a = input<double>("Введите а");
    auto x = input<double>("Введите x");
    double w;

    if (x == 0)
    {
        cout << "ERROR: нельзя подставлять ноль под логарифм" << endl;
    }
    else if (abs(x) < 1 && x != 0)
    {
        w = a * log10(abs(x));
        printf("w(%f, %f)=%f", a, x, w);
    }
    else if (a < x * x)
    {
        w = sqrt(a - (x * x));
        printf("w(%f, %f)=%f", a, x, w);
    }
    else
    {
        printf("Значение функции не определено");
    }
}

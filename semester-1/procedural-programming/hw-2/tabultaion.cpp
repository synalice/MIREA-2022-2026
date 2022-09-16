#include <iostream>
#include <cmath>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");

    for (double x = -4; x <= 4; x += 0.5)
    {
        double y = (x * x - 2 * x + 2) / (x - 1);
        if (abs(y) != 1.0 / 0)
            printf("y(%f)=%f\n", x, y);
        else
            printf("y(%f) не определен\n", x);
    }
}

#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    for (double x = -4; x <= 4; x += 0.5)
    {
        double y = (x * x - 2 * x + 2) / (x - 1);
        if (x == 1)
        {
            printf("y(%4.1f) не определён\n", x);
        }
        else
        {
            printf("y(%4.1f) = %g\n", x, y);
        }
    }

    return 0;
}

#define _USE_MATH_DEFINES

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    double r, R, h;

    cout << "Введите радиус 1: ";
    cin >> R;

    cout << "Введите радиус 2: ";
    cin >> r;

    cout << "Введите высоту: ";
    cin >> h;

    if (r < 0 || R < 0)
    {
        cout << "ERROR: радиус не может быть отрицательным" << endl;
    }
    else if (h < 0)
    {
        cout << "ERROR: высота не может быть отрицательной" << endl;
    }
    else
    {
        cout << "V=" << (double)1 / 3 * M_PI * h * (R * R + R * r + r * r) << endl;

        double L = sqrt(h * h + pow((R - r), 2));
        cout << "S=" << M_PI * (R * R + (R + r) * L + r * r) << endl;

        if (r == 0 && R != 0 || R == 0 && r != 0)
        {
            cout << "INFO: Ваша фигура - конус" << endl;
        }
        else if (r == 0 && R == 0)
        {
            cout << "INFO: Вашей фигуры не существует в пространстве :(" << endl;
        }
        else if (r == R)
        {
            cout << "INFO: Ваша фигура - цилиндр" << endl;
        }
        else if (r != R)
        {
            cout << "INFO: Ваша фигура - усечённый конус" << endl;
        }
    }
}

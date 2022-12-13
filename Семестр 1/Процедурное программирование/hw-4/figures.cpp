#define _USE_MATH_DEFINES

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int getUserChoice()
{
    cout << "1 - прямоугольник" << endl;
    cout << "2 - треугольник" << endl;
    cout << "3 - круг" << endl;
    cout << "Введите номер выбранной фигуры (1, 2 или 3): ";
    int user_choice = 0;
    cin >> user_choice;
    return user_choice;
}

void validateRectangleInput(double a, double b) {
    if (a <= 0 || b <= 0) {
        cout << "ОШИБКА: Такого прямоугольника не существует!" << endl;
        exit(1);
    }
}

double getRectangleArea()
{
    double a, b;
    cout << "Через пробел введите стороны прямоугольника: ";
    cin >> a >> b;
    validateRectangleInput(a, b);
    return a * b;
}

void validateTriangleInput(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0 || (a + b < c || a + c < b || b + c < a)) {
        cout << "ОШИБКА: Такого треугольника не существует!" << endl;

        exit(1);
    }
}

double getTriangleArea() {
    double a, b, c;
    cout << "Через пробел введите три стороны треугольника: ";
    cin >> a >> b >> c;
    validateTriangleInput(a, b, c);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void validateCircleInput(double R) {
    if (R <= 0) {
        cout << "ОШИБКА: Такого круга не существует!" << endl;
        exit(1);
    }
}

double getCircleArea() {
    double R;
    cout << "Введите радиус круга: ";
    cin >> R;
    validateCircleInput(R);
    return M_PI * R * R;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int user_choice = getUserChoice();
    double area;
    switch (user_choice)
    {
    case 1:
        area = getRectangleArea();
        cout << "Площадь вашего прямоугольника: " << area << endl;
        break;
    case 2:
        area = getTriangleArea();
        cout << "Площадь вашего треугольника: " << area << endl;
        break;
    case 3:
        area = getCircleArea();
        cout << "Площадь вашего круга: " << area << endl;
        break;
    default:
        cout << endl << "Я не знаю такой фигуры" << endl;
        break;
    }

    return 0;
}

#include <iostream>
#include <clocale>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    
    std::cout << "Введите a, b и с:" << std::endl;
    std::cin >> a >> b >> c;

    if (a != 0) {
        double D = b * b - 4 * a * c;
      
        if (D < 0) {
            std::cout << "Нет решений" << std::endl;
            return 0;
        }

        std::cout << (-b + sqrt(D)) / (2 * a) << std::endl;

        if (D > 0) {
            std::cout << (-b - sqrt(D)) / (2 * a) << std::endl;
        }
    } else {
        if (b == 0) {
            if (c == 0) {
                std::cout << "Любое число" << std::endl;
            } else {
                std::cout << "Решений нет" << std::endl;
            }
        } else {
            std::cout << (-c / b);
        }
    }

    return 0;
}
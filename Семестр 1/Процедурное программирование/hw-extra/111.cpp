#include <clocale>
#include <iostream>
#include <vector>

void Hanoi(int n, int from, int to, int& total)
{
    if (n > 0) {
        int tmp = 6 - from - to;
        Hanoi(n - 1, from, tmp, total);
        printf("%d -> %d\n", from, to);
        total++;
        Hanoi(n - 1, tmp, to, total);
    }
}

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    int total {};
    int n {};
    std::cout << "Введите число колец: ";
    std::cin >> n;
    Hanoi(n, 1, 3, total);
    std::cout << "Кол-во перестановок:\n" << total << std::endl;

    return 0;
}

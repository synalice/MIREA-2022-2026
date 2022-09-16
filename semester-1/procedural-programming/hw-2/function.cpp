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
	auto x = input<double>("Введите x");
	auto y = input<double>("Введите y");
	auto b = input<double>("Введите b");

	if (b - y <= 0)
	{
		printf("ERROR: ноль или отрицательное число в логарифме");
	}
	else if (b - x < 0)
	{
		printf("ERROR: отрицательное число под корнем");
	}
	else
	{
		cout << "RESULT: " << log(b - y) * sqrt(b - x) << endl;
	}
}

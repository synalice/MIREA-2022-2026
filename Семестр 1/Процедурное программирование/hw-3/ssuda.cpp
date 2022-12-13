#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#include <string>
#include <Windows.h>

using namespace std;

template <typename T>
T input(string message)
{
	cout << message << ": ";
	T value{};
	cin >> value;
	return value;
}

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	double S = input<double>("Введите сумму займа (S)");
	while (S < 0)
	{
		double S = input<double>("Введите сумму (S) еще раз");
	}

	double n = input<double>("Введите срок займа (n)");
	while (n < 0)
	{
		double n = input<double>("Введите кол-во лет (n) еще раз");
	}

  double m = input<double>("Введите месячную выплату (m)");
  while (n < 0)
  {
    double n = input<double>("Введите месячную выплату (m) еще раз");
  }
	double r = 0;
	double r2 = 100;
	double mc;
	if (S > m * n)
	{
		do
		{
			r2 = r2 - 0.00001;
			mc = (S * r2 * (pow(1 + r2, n))) / (12 * ((pow(1 + r2, n)) - 1));
		} while (mc > m);
		cout << r2 * 100.0 << "%" << endl;
	}
	else
	{
		do
		{
			r = r + 0.00001;
			mc = (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1));
		} while (mc < m);
		cout << r * 100.0 << "%" << endl;
	}
	if (m == 0)
	{
		cout << "0 %" << endl;
	}
	return 0;
}
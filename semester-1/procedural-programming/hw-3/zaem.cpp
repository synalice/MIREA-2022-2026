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
  setlocale(LC_ALL, "Russian");

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

  double p = input<double>("Введите проценты займа (p)");
  double r = p / 100.0;

  if (p == 0)
  {
    double m = S / (12 * n);
    cout << "Ваша месячная выплата равна: " << m << endl;
  }
  else if ((S <= 0) || (n <= 0) && (p == 0 || p != 0))
  {
    cout << "Некорректные данные" << endl;
  }
  else if ((12 * ((pow(1 + r, n)) - 1)) != 0)
  {
    double m = (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1));
    if (m > 0)
    {
      cout << "Ваша месячная выплата равна: " << m << endl;
    }
    else
    {
      cout << "Ошибка!" << endl;
    }
  }
  else
  {
    cout << "Ошибка" << endl;
  }
}

#include <iostream>
#include <cmath>

using namespace std;

void del(int a, int b)
{
	while ((a != 0) && (b != 0))
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	cout << endl << "НОД делением: " << a + b << endl;
}

void nod(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << endl << "НОД вычитанием: " << a << endl;
}

int main()
{
	cout << "Алгоритм евклида" << endl;
	int a, b;
	cout << "Введите числа a и b: ";
	cin >> a >> b;

	if (a == 0 || b == 0) {
		cout << endl << "НОД не существует" << endl;
	}
	else if (a < 0 || b < 0) {
		cout << endl << "Такое я пока не умею :(" << endl;
	}
	else {
		del(a, b);
		nod(a, b);
	}
}

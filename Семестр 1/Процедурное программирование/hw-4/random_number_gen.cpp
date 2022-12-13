#include <iostream>
#include <time.h>
#include <clocale>

using namespace std;

void big()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	int m, i, c, S0, S1, b;
	m = 25173;
	c = 65537;
	b = 13849;
	cout << "i – количество чисел" << endl;
	cin >> i;
	S0 = time(0);
	for (int j = 0; j < i; j++)
	{
		S1 = (m * S0 + b) % c;
		cout << S1 << " ";
		S0 = S1;
	}
}
void small()
{
	setlocale(0, "");
	int m, i, c, S0, S1, b;
	m = 37;
	c = 64;
	b = 3;
	cout << "i – количество чисел" << endl;
	cin >> i;
	S0 = time(0);
	for (int j = 0; j < i; j++)
	{
		S1 = (m * S0 + b) % c;
		cout << S1 << " ";
		S0 = S1;
	}
}
void main()
{
	setlocale(0, "");
	cout << "Выберите какие числа вы хотите: " << endl;
	cout << "1 - маленькие" << endl;
	cout << "2 - большие" << endl;
	double ch = 0;
	int ch1;
	do {
		cin >> ch;
		if (ch < 1 || ch > 2 || double(ch) - int(ch) != 0)
		{
			cout << "Неверный ввод. Попробуйте ещё раз: ";
			cin.clear();
			cin.ignore(1000000, '\n');
		}
		cout << endl;
	} while (ch < 1 || ch > 2 || double(ch) - int(ch) != 0);
	ch1 = int(ch);
	switch (ch1)
	{
	case 1:
		small();
		break;
	case 2:
		big();
		break;
	}
}

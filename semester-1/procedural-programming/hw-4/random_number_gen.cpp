#include <iostream>
#include <clocale>
#include <random>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int number_of_generations{};
	cout << "Солько чисел мне сгенерировать? ";
	cin >> number_of_generations;

	int number_size{};
	cout << "Какого размера сгенерировать числа? (1 - маленькие, 2 - большие) ";
	cin >> number_size;

	switch (number_size)
	{
	case 1:
		double m = 37;
		double b = 3;
		double c = 64;
		
		for (int i = 0; i < number_of_generations; i++)
		{
			double s = (m * )
		}

		break;
	case 2:
		double m = 25173;
		double b = 13849;
		double c = 65537;

		break;
	default:
		cout << "Я такое не умею" << endl;
		break;
	}
}

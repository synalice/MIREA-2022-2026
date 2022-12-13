#include <iostream>
#include <clocale>

void main()
{
	std::setlocale(LC_ALL, "ru_RU.UTF-8");

	double num1;
	double num2;

	std::cout << "Enter two numbers: " << std::endl;
	std::cin >> num1 >> num2;

	std::cout << "Sum: " << num1 + num2 << std::endl;
	std::cout << "Sub: " << num1 - num2 << std::endl;
	std::cout << "Mul: " << num1 * num2 << std::endl;
	if (num2 != 0)
	{
		std::cout << "Div: " << num1 / num2 << std::endl;
	}
	else
	{
		std::cout << "Div: " << "can't divide " << num1 << " by zero" << std::endl;
	}
}

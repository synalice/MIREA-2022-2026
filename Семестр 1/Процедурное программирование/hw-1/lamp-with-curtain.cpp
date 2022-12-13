#include <iostream>
#include <clocale>

void main()
{
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	
	std::cout << "Enter 1 for YES or 0 for NO" << std::endl;

	int day;
	int curtains;
	int lamp;

	std::cout << "Is is a day outside? ";
	std::cin >> day;

	std::cout << "Are curtains open? ";
	std::cin >> curtains;

	std::cout << "Is the lamp on? ";
	std::cin >> lamp;

	if (day && curtains || lamp) 
	{
		std::cout << "It is bright inside!" << std::endl;
	}
	else
	{
		std::cout << "It is dark inside!" << std::endl;
	}
}
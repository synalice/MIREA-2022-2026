#include <iostream>

void main()
{
	double b;
	std::cout << "Enter b: ";
	std::cin >> b;

	double c;
	std::cout << "Enter c: ";
	std::cin >> c;

	if (b == 0 && c == 0)
	{
		std::cout << "Result: x is any number" << std::endl;
	}
	else if (b == 0)
	{
		std::cout << "Result: equation can't be solved" << std::endl;
	}
	else if (c == 0)
	{
		std::cout << "Result: x=" << 0 << std::endl;
	}
	else
	{
		std::cout << "Result: " << -c / b << std::endl;
	}
}
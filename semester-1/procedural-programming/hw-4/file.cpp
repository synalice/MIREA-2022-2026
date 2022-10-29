#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <clocale>

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	// "Создать файл, записать в него 10 чисел..."
	fstream file;
	file.open("C:\\Users\\Professional\\Desktop\\file.txt", ios::out);
	for (int i = 1; i <= 10; i++) {
	    printf("Введите число %2d: ", i);
	    double user_input{};
	    cin >> user_input;
	    file << user_input << endl;
	}
	file.close();

	setlocale(LC_ALL, "English");

	// "...закрыть, потом вновь открыть файл и найти сумму чисел."
	file.open("C:\\Users\\Professional\\Desktop\\file.txt", ios::in);
	double total_sum = 0;
	string line;
	while (getline(file, line))
	{
		double stoded = stod(line);
		total_sum = total_sum + stoded;
	}

	setlocale(LC_ALL, "Russian");
	cout << "Сумма чисел в созданном файле: " << total_sum << endl;

	return 0;
}

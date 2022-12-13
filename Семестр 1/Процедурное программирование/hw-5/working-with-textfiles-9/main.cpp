#include <iostream>
#include <fstream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	char ch{};
	fstream file;
	file.open("textfiles9.txt");

	while (file >> noskipws >> ch) {
		cout << int(ch) << endl;
	}
}

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	char ch{};
	fstream file;
	file.open("textfiles9.txt");

	while (file >> noskipws >> ch) {
		cout << int(ch) << endl;
	}
}

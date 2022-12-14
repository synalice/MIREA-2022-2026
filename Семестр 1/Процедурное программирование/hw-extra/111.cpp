#include <iostream>
#include <clocale>
#include <vector>

void Hanoi(int n, int from, int to) {
	if (n > 0) {
		int tmp = 6 - from - to;
		Hanoi(n - 1, from, tmp);
		printf("%d -> %d\n", from, to);
		Hanoi(n - 1, tmp, to);
	}
}

int main() {
	std::setlocale(LC_ALL, "ru_RU.UTF-8");

	int n{};
	std::cout << "Введите число колец: ";
	std::cin >> n;
	Hanoi(n, 1, 3);

	return 0;
}

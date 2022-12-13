#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	int result = 0;
	int numOfBalls{};
	vector<int> balls{};

	cout << "Введите кол-во шариков: " << ends;
	cin >> numOfBalls;

	for (int i = 0; i < numOfBalls; i++) {
		balls.push_back(i);
	}

	do {
		for (int i = 0; i < balls.size(); i++)
		{
			if (i == balls[i]) {
				result++;
				break;
			}
		}
	} while (next_permutation(balls.begin(), balls.end()));

	cout << result << ends;

	return 0;
}

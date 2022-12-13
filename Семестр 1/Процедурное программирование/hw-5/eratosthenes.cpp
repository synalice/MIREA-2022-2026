#include <iostream>
#include <cmath>
#include <vector>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	cout << "Решето Эратосфена" << endl;
	int n;
	cout << "Введите натуральное число начиная от 2: ";
	cin >> n;

	if (n < 2) {
		cout << "Число дожно быть больше 2" << endl;
	}
	else {
		vector<int> a{};
		
		for (int i = 0; i < n + 1; i++)
			a.push_back(i);
		
		cout << "Ответ: ";
		
		for (int p = 2; p < n + 1; p++)
		{
			if (a[p] != 0)
			{
				cout << a[p] << " ";
				for (int j = p * p; j < n + 1; j += p)
					a[j] = 0;
			}
		}
	}
}


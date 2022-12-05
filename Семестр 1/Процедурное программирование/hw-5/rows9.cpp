#include <iostream>
#include <cmath>

using namespace std;

double FindA(int n, int x) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return x;
	}
	else if (n == 3) {
		return pow(x, 3);
	}
	else {
		double anm1 = FindA(n - 1, x);
		double anm2 = FindA(n - 2, x);
		double anm3 = FindA(n - 3, x);

		double del1 = 12 - anm1 * x;
		double del2 = pow(anm2, 2) + sqrt(anm3);
		double a = del1 / del2;
		return a;
	}
}

int main() {
	double x{}, epsilon{};
	cout << "Введите числа x и эпсилон: ";
	cin >> x >> epsilon;

	double a{}, a1{};

	for (int n = 15; n < 10000; n++)
	{
		a = FindA(n, x);
		a1 = FindA(n - 1, x);

		if (abs(a - a1) < epsilon) {
			cout << "Первое найденный член последовательности: " << a << endl;
		}
	}
}

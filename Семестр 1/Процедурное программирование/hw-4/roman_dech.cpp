#include <iostream>
#include <string>

using namespace std;

// Я не горд этим кодом. Он не мой

int Decoder(string a) {
	int j = a.length();
	a += "000";
	int NUMBER = 0;
	int x = 0, y = 0, z = 0, t = 0,
		kv = 0, kl = 0, kd = 0,
		k2 = 0,
		k3 = 1001;
	for (int i = 0; i < j; i++)
	{
		switch (a[i])
		{
		case 48: y = 0; break;
		case 73: x = 1; break;
		case 86: x = 5; kv = kv + 1;  break;
		case 88: x = 10; break;
		case 76: x = 50; kl = kl + 1; break;
		case 67: x = 100; break;
		case 68: x = 500; kd = kd + 1; break;
		case 77: x = 1000; break;
		}
		switch (a[i + 1])
		{
		case 48: y = 0; break;
		case 73: y = 1; break;
		case 86: y = 5; break;
		case 88: y = 10; break;
		case 76: y = 50; break;
		case 67: y = 100; break;
		case 68: y = 500; break;
		case 77: y = 1000; break;
		}
		switch (a[i + 2])
		{
		case 48: z = 0; break;
		case 73: z = 1; break;
		case 86: z = 5; break;
		case 88: z = 10; break;
		case 76: z = 50; break;
		case 67: z = 100; break;
		case 68: z = 500; break;
		case 77: z = 1000; break;
		}
		switch (a[i + 3])
		{
		case 48: t = 0; break;
		case 73: t = 1; break;
		case 86: t = 5; break;
		case 88: t = 10; break;
		case 76: t = 50; break;
		case 67: t = 100; break;
		case 68: t = 500; break;
		case 77: t = 1000; break;
		}
		if (x < y)
		{
			NUMBER = NUMBER - x;
			k3 = x;
		}
		else if (y < k3)
		{
			NUMBER = NUMBER + x;
		}
		else { k2 = k2 + 1; }
		if (y - x == x) { k2 = k2 + 1; }
		if ((x < z && y < z)
			or (kl > 1) or (kd > 1) or (kv > 1)
			or ((x == y) && (y == z) && (z == t) && (t == x))
			or (k2 > 0))
		{
			cout << "Некорректная запись числа" << endl;
			return (0);
		}
	}
	return (NUMBER);
}

int main() {
	setlocale(0, "");

	string b;
	cout << "Введите число:" << endl;
	getline(cin, b);
	cout << Decoder(b);
	return 0;
}
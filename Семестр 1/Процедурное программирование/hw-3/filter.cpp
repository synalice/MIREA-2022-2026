#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <clocale>
#include <Windows.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <ctype.h>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	fstream file;
	file.open("C:\\Users\\Professional\\git\\MIREA-2022-2026\\semester-1\\procedural-programming\\hw-3\\filter.cpp\\34.txt", ios::in);
	if (file.is_open())
	{
		string tp;
		string last_char = "";
		while (getline(file, tp))
		{
			for (int i = 0; i <= tp.length(); i++)
			{
				if (isdigit(tp[i]))
				{
					last_char = tp[i];
					cout << tp[i];
				}
				else
				{
					if (last_char != " ")
					{
						last_char = " ";
						cout << " ";
					}
				}
			}

			cout << endl;
		}
		file.close();
	}

	return 0;
}
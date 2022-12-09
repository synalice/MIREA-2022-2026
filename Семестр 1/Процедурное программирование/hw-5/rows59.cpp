#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

constexpr auto UNINITIALIZED = -1;

using namespace std;
using row = int;
using col = int;

vector<string> SplitInputBySpace(string row) {
	vector<string> rowElems;
	int tokenStart = UNINITIALIZED;
	int tokenEnd = UNINITIALIZED;

	for (int i = 0; i < row.size(); i++) {
		if (row[i] != ' ' && row[i] != '\t') {
			if (tokenStart == UNINITIALIZED) {
				tokenStart = i;
				continue;
			}
		}
		else {
			tokenEnd = i;
			if (tokenStart != UNINITIALIZED && tokenEnd != UNINITIALIZED) {
				string elem = row.substr(tokenStart, tokenEnd - tokenStart);
				rowElems.push_back(elem);
				tokenStart = UNINITIALIZED;
				tokenEnd = UNINITIALIZED;
			}
			tokenEnd = UNINITIALIZED;
		}
	}

	if (tokenStart != UNINITIALIZED && tokenEnd == UNINITIALIZED) {
		string elem = row.substr(tokenStart, row.size());
		rowElems.push_back(elem);
	}

	return rowElems;
}

bool RowIsValid(vector<string> elems, int cols) {
	if (elems.size() != cols) {
		cout << "Кол-во элементов в строке не равно " << cols << endl;
		return false;
	}
	for (string s : elems) {
		try {
			(void)stod(s);
		}
		catch (invalid_argument) {
			cout << "В вводе присутствует ошибка" << endl;
			return false;
		}
		catch (out_of_range) {
			cout << "Одно из введенных чисел слишком большое" << endl;
			return false;
		}
	}
	return true;
}

void ReprintRows(vector<vector<double>> matrixRows) {
	for (vector<double> row : matrixRows) {
		for (double e : row) {
			cout << e << " ";
		}
		cout << endl;
	}
}

vector<vector<double>> GetMatrix(int rows, int cols) {
	string input;
	vector<vector<double>> matrix;
	bool errorHappened = false;

	cout << "-----начало-----" << endl;
	for (int i = 0; i < rows; i++) {
		while (true) {
			if (errorHappened == true) {
				cout << endl << "-----начало-----" << endl;
				ReprintRows(matrix);
			}
			getline(cin, input);
			vector<string> elems = SplitInputBySpace(input);
			if (RowIsValid(elems, cols) == false) {
				errorHappened = true;
				continue;
			}
			else {
				errorHappened = false;
				vector<double> elemsAsInt;
				for (string elem : elems) {
					elemsAsInt.push_back(stod(elem));
				}
				matrix.push_back(elemsAsInt);
				break;
			}
		}
	}
	cout << "-----конец-----" << endl;
	return matrix;
}

struct matrixParams {
	int rows;
	int cols;
};

matrixParams GetMatrixParams() {
	string rows, cols;
	matrixParams mp{};

	while (true)
	{
		cout << "Введите кол-во строк матрицы: ";
		getline(cin, rows);
		cout << "Введите кол-во столбцов матрицы: ";
		getline(cin, cols);

		try {
			mp.rows = stoi(rows);
			mp.cols = stoi(cols);
		}
		catch (invalid_argument) {
			cout << "ERROR: Недопустимое значение" << endl;
			continue;
		}
		catch (out_of_range) {
			cout << "ERROR: Недопустимое значение" << endl;
			continue;
		}


		if (mp.rows < 2 || mp.cols < 2) {
			cout << "ERROR: Кол-во строк или столбцов не может быть меньше 2-х!" << endl;
			continue;
		}
		else {
			break;
		}
	}
	return mp;
}

struct allSaddlePoints {
	double value;
	vector<pair<row, col>> coords;
};

struct singlePoint {
	double value;
	pair<row, col> coords;
};

double FindIntersectingPoints(vector<double> v1, vector<double> v2) {
	vector<double> v3;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(
		v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		back_inserter(v3)
	);

	if (v3.size() != 0) {
		return v3[0];
	}
	else {
		return -1;
	}
}

allSaddlePoints FindSaddlePoint(vector<vector<double>> matrix, matrixParams mp) {
	vector<singlePoint> smallestPoints;
	vector<singlePoint> biggestPoints;

	vector<double> smallestElems;
	vector<double> biggestElems;

	singlePoint min;
	singlePoint max;

	double maxElem{};

	for (int i = 0; i < mp.rows; i++) {
		double minElem = *min_element(matrix[i].begin(), matrix[i].end());
		for (int j = 0; j < mp.cols; j++) {
			if (matrix[i][j] == minElem) {
				min.value = matrix[i][j];
				min.coords.first = i+1;
				min.coords.second = j+1;
			}
		}
		smallestElems.push_back(min.value);
		smallestPoints.push_back(min);
	}

	vector<double> tmpColumn;
	vector<double> maxElemInEachCol;
	for (int i = 0; i < mp.cols; i++) {
		for (int j = 0; j < mp.rows; j++) {
			tmpColumn.push_back(matrix[j][i]);
		}
		maxElemInEachCol.push_back(*max_element(tmpColumn.begin(), tmpColumn.end()));
		tmpColumn.clear();
	}

	for (int i = 0; i < mp.cols; i++) {
		for (int j = 0; j < mp.rows; j++) {
			if (matrix[j][i] == maxElemInEachCol[i]) {
				max.value = matrix[j][i];
				max.coords.first = j+1;
				max.coords.second = i+1;
			}
			biggestElems.push_back(max.value);
			biggestPoints.push_back(max);
		}
	}

	allSaddlePoints ap;
	ap.value = FindIntersectingPoints(biggestElems, smallestElems);

	if (ap.value != -1) {
		for (singlePoint p : smallestPoints) {
			if (p.value == ap.value) {
				ap.coords.push_back(p.coords);
			}
		}
		for (singlePoint p : biggestPoints) {
			if (p.value == ap.value) {
				ap.coords.push_back(p.coords);
			}
		}

		sort(ap.coords.begin(), ap.coords.end());
		ap.coords.erase(unique(ap.coords.begin(), ap.coords.end()), ap.coords.end());

		return ap;
	}
	else {
		return ap;
	}
}

void PrintSaddlePoint(allSaddlePoints ap) {
	if (ap.value != -1) {
		cout << endl;
		cout << "Седловая точка равна " << ap.value << endl;
		cout << "Координаты: ";
		for (pair<row, col> coord : ap.coords) {
			cout << "(" << coord.first << ", " << coord.second << ") ";
		}
		cout << endl;
	}
	else {
		cout << "Седловая точка отсутствует" << endl;
	}
}

int main() {
	matrixParams mp = GetMatrixParams();
	vector<vector<double>> matrix = GetMatrix(mp.rows, mp.cols);
	allSaddlePoints ap = FindSaddlePoint(matrix, mp);
	PrintSaddlePoint(ap);
}

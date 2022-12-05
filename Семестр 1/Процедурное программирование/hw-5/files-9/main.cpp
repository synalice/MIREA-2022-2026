#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

constexpr auto UNINITIALIZED = -1;

using namespace std;

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

vector<double> ConvertVecStrToVecDouble(vector<string> v) {
	vector<double> result;

	for (string elem : v) {
		try {
			result.push_back(stod(elem));
		}
		catch (invalid_argument) {
			cout << "ОШИБКА: В одном из файлов находится не число. Пропускаю." << endl;
		}
	}

	return result;
}

int main() {
	fstream fileA;
	fstream fileB;
	ofstream fileC;

	fileA.open("textfilea.txt");
	fileB.open("textfileB.txt");
	fileC.open("textfileC.txt");
	
	string fileAContents((istreambuf_iterator<char>(fileA)), istreambuf_iterator<char>());
	string fileBContents((istreambuf_iterator<char>(fileB)), istreambuf_iterator<char>());
	
	string fileAPlusFileB = fileAContents + " " + fileBContents;
	vector<string> splittedElems = SplitInputBySpace(fileAPlusFileB);
	vector<double> elemsAsDouble = ConvertVecStrToVecDouble(splittedElems);

	sort(elemsAsDouble.begin(), elemsAsDouble.end());
	for (double elem : elemsAsDouble) {
		fileC << elem << " ";
	}

	fileA.close();
	fileB.close();
	fileC.close();
}

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
	fstream readFileA;
	readFileA.open("textfilea.txt");
	fstream readFileB;
	readFileB.open("textfileB.txt");
	ofstream writeFileC;
	writeFileC.open("textfileC.txt");

	string fileAContents((istreambuf_iterator<char>(readFileA)), istreambuf_iterator<char>());
	string fileBContents((istreambuf_iterator<char>(readFileB)), istreambuf_iterator<char>());

	readFileA.close();
	readFileB.close();

	fstream writeFileA;
	writeFileA.open("textfilea.txt");
	fstream writeFileB;
	writeFileB.open("textfileB.txt");

	vector<string> aSplittedElems = SplitInputBySpace(fileAContents);
	vector<double> aElemsAsDouble = ConvertVecStrToVecDouble(aSplittedElems);
	sort(aElemsAsDouble.begin(), aElemsAsDouble.end());

	for (double elem : aElemsAsDouble) 
		writeFileA << elem << " ";
	writeFileA.close();

	vector<string> bSplittedElems = SplitInputBySpace(fileBContents);
	vector<double> bElemsAsDouble = ConvertVecStrToVecDouble(bSplittedElems);
	sort(bElemsAsDouble.begin(), bElemsAsDouble.end());

	for (double elem : bElemsAsDouble)
		writeFileB << elem << " ";
	writeFileB.close();

	string aPlusB = fileAContents + " " + fileBContents;

	vector<string> splittedElems = SplitInputBySpace(aPlusB);
	vector<double> elemsAsDouble = ConvertVecStrToVecDouble(splittedElems);
	sort(elemsAsDouble.begin(), elemsAsDouble.end());

	for (double elem : elemsAsDouble)
		writeFileC << elem << " ";
	writeFileC.close();
}

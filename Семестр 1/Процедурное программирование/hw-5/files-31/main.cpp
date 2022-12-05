#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream readFile("textfiles31.txt");
	string fileContents((istreambuf_iterator<char>(readFile)), istreambuf_iterator<char>());
	
	random_shuffle(fileContents.begin(), fileContents.end());

	ofstream writeFile;
	wFile.open("textfiles31.txt");
	wFile << fileContents;
}
	
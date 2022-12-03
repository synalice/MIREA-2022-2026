#include <iostream>
#include <clocale>

using namespace std;

double getInputFromUser() {
  double user_input = 0;
  cout << "Я могу определить знак вашего числа!" << endl;
  cout << "Введите число: " << ends;
  cin >> user_input;
  return user_input;
}

string determineNumSign(int input) {
  string to_return;

  if (input > 0) {
    to_return = "ПЛЮС";
  }
  else if (input < 0) {
    to_return = "МИНУС";
  }
  else {
    to_return = "ЧИСЛО РАВНО НУЛЮ";
  }

  return to_return;
}

int main() {
  setlocale(LC_ALL, "Russian");

  double user_input = getInputFromUser();
  string sign = determineNumSign(user_input);

  cout << "Знак вашего числа: " << sign;

  return 0;
}

#include <iostream>
#include <clocale>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;

void print_color(int color_code, string element) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color_code);
  cout << element << " ";
  this_thread::sleep_for(chrono::milliseconds(1));
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  // Colors
  int WHITE_ON_BLUE = 31;
  int RED = 68;
  int WHITE = 255;
  int WHITE_ON_BLACK = 15;

  for (int i = 0; i < 13; i++) {
    cout << endl;
    for (int j = 0; j < 25; j++) {
      if (i < 6 && j < 8) {
        print_color(WHITE_ON_BLUE, "*");
      }
      else if (i % 2 == 0) {
        print_color(RED, " ");
      }
      else {
        print_color(WHITE, " ");
      }
    }
  }
  print_color(WHITE_ON_BLACK, "\n");
  return 0;
}

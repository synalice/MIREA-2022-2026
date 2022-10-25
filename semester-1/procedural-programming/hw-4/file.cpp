#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <clocale>

using namespace std;


int main() {
  setlocale(LC_ALL, "Russian");

  // Генерация случайных чисел
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10);
  
  // "Создать файл, записать в него 10 чисел..."
  fstream file;
  file.open("C:\\Users\\Professional\\Desktop\\file.txt", ios::out);
  for (int i = 0; i < 10; i++) {
    file << dist6(rng) << endl;
  }
  file.close();

  // "...закрыть, потом вновь открыть файл и найти сумму чисел."
  file.open("C:\\Users\\Professional\\Desktop\\file.txt", ios::in);
  int total_sum = 0;
  string line;
  while (getline(file, line))
  {
    total_sum = total_sum + stoi(line);
  }

  cout << "Сумма чисел в созданном файле: " << total_sum << endl;

  return 0;
}

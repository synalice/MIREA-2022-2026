#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <clocale>

std::vector<int> GenerateRandomNumber() {
    std::set<int> result;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 9);
    
    while (true)
    {
        if (result.size() != 4) {
            result.insert(dist(mt));
        }
        else {
            return std::vector<int>(result.begin(), result.end());
        }
    }
}

std::vector<int> GetUserInput() {
    std::cout << "Введите число, которое по вашему мнению задумал компьютер:" << std::endl;
    int user_input{};
    std::cin >> user_input;
    
    std::vector<int> result;

    while (user_input > 0)
    {
        result.push_back(user_input%10);
        user_input /= 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

void PrintRandomNumber(std::vector<int> num) {
    std::cout << "Компьютер задумал число:" << std::endl;
    for (int i : num) {
        std::cout << i;
    }
    std::cout << std::endl;
}

void PrintResults(std::vector<int> random_number, std::vector<int> user_guess) {
    int plus{};
    int minus{};

    for (int i = 0; i < random_number.size(); i++) {
        if (i > user_guess.size()) {
            break;
        }
        else if (random_number[i] == user_guess[i]) {
            plus++;
        }
        else if (
            random_number[i] != user_guess[i]
            &&
            std::find(
                random_number.begin(),
                random_number.end(),
                user_guess[i]
            ) != random_number.end()) {
            minus++;
        }
    }
    std::cout << "Плюсов  (+): " << plus << std::endl;
    std::cout << "Минусов (-): " << minus << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::vector<int> random_number = GenerateRandomNumber();
    PrintRandomNumber(random_number);
    std::vector<int> user_guess = GetUserInput();
    PrintResults(random_number, user_guess);
    return 0;
}
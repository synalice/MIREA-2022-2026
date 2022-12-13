#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <clocale>

typedef int teacher;
typedef int student;

/**
* Разделяет строку по пробелам и табам.
*/
std::vector<std::string> SplitStrBySpace(std::string str) {
	constexpr auto UNINITIALIZED = -1;

	std::vector<std::string> elems;
	int token_start = UNINITIALIZED;
	int token_end = UNINITIALIZED;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ' && str[i] != '\t') {
			if (token_start == UNINITIALIZED) {
				token_start = i;
				continue;
			}
		}
		else {
			token_end = i;
			if (token_start != UNINITIALIZED && token_end != UNINITIALIZED) {
				std::string elem = str.substr(token_start, token_end - token_start);
				elems.push_back(elem);
				token_start = UNINITIALIZED;
				token_end = UNINITIALIZED;
			}
			token_end = UNINITIALIZED;
		}
	}

	if (token_start != UNINITIALIZED && token_end == UNINITIALIZED) {
		std::string elem = str.substr(token_start, str.size());
		elems.push_back(elem);
	}

	return elems;
}

/**
* Проверяет, верность ввода монахов.
*/
bool InputIsValid(std::vector<std::string> input) {
	if (input.size() != 4) {
		std::cerr << "ОШИБКА: Неверное кол-во монахов" << std::endl;
		return false;
	}
	return true;
}

/**
* Преобразует вектор строк к вектору чисел.
*/
std::vector<int> VecStrToVecInt(std::vector<std::string> vec) {
	std::vector<int> result;
	for (std::string s : vec) {
		try {
			result.push_back(stoi(s));
		}
		catch (std::invalid_argument) {
			std::cerr << "ОШИБКА: Элемент " << s << " не является числом" << std::endl;
		}
	}
	return result;
}

/**
* Функция отвечает за ввод пользователем всех монахов. Ввод прекращается при
* вводе монаха под номером один (1).
*/
void FillMonks(std::unordered_map<student, teacher>* monk_map) {
	std::vector<int> teachers;
	
	std::cout << "Введите исходные данные о монахах:" << std::endl;

	std::string input;
	while (true) {
		getline(std::cin, input);
		std::vector<std::string> splitted_input = SplitStrBySpace(input);
		if (InputIsValid(splitted_input) == false) {
			continue;
		}
		std::vector<int> monk_ID_s = VecStrToVecInt(splitted_input);
		int teacher = monk_ID_s[0];

		if (std::find(teachers.begin(), teachers.end(), teacher) != teachers.end()) {
			std::cerr << "ОШИБКА: Такой учитель уже существует" << std::endl;
			continue;
		}
		else {
			teachers.push_back(teacher);
		}

		for (int i = 0; i < monk_ID_s.size() - 1; i++) {
			if (monk_ID_s[i + 1] == 0) {
				continue;
			}

			monk_map->insert({ monk_ID_s[i + 1], teacher });
		}

		if (teacher == 1) {
			break;
		}
	}
}

/**
* Функция находит учителя выбранного монаха, учителя его учителя и т.д. до
* монаха под номером один (1). Все учителя записываются в единый массив
* `teachers`.
*/
void FindTeachers(std::unordered_map<student, teacher>* monk_map, int monk, std::vector<teacher>* teachers) {

	try {
		int teacher = monk_map->at(monk);
		if (teacher == 1) {
			return;
		}
		teachers->push_back(teacher);
		FindTeachers(monk_map, teacher, teachers);
	}
	catch (std::out_of_range)
	{
		std::cerr << "Такого монаха не существует" << std::endl;
	}
}

/**
* Функция проверяет, является ли указанный номер существующим монахом.
*/
bool IsMonk(std::unordered_map<student, teacher> monk_map, int monk) {
	try {
		(void)monk_map.at(monk);
		return true;
	}
	catch (std::out_of_range)
	{
		return false;
	}
}

/**
* Функция отвечает за обработку подпрограммы один (1) (см. условие задачи).
*/
void SubProgrammOne(std::unordered_map<student, teacher> monk_map, std::vector<int> params) {
	int monk = params[0];

	if (IsMonk(monk_map, monk) == false) {
		std::cout << monk << " - не монах" << std::endl;
		return;
	}

	std::vector<teacher> teachers;
	FindTeachers(&monk_map, monk, &teachers);
	std::cout << monk << " - монах, его учителя ";
	for (int i = 0; i < teachers.size(); i++) {
		if (&teachers[i] == &teachers.back()) {
			std::cout << teachers[i] << std::endl;;
		}
		else {
			std::cout << teachers[i] << ", ";
		}
	}
}

/**
* Функция отвечает за обработку подпрограммы два (2) (см. условие задачи).
*/
void SubProgrammTwo(std::unordered_map<student, teacher> monk_map, std::vector<int> params) {
	for (int monk : params) {
		if (IsMonk(monk_map, monk) == false) {
			std::cout << monk << " - не монах" << std::endl;
			return;
		}
	}

	int monk1 = params[0];
	int monk2 = params[1];
	std::vector<teacher> monk_1_teachers;
	std::vector<teacher> monk_2_teachers;
	FindTeachers(&monk_map, monk1, &monk_1_teachers);
	FindTeachers(&monk_map, monk2, &monk_2_teachers);

	std::vector<teacher> same_teachers;
	std::sort(monk_1_teachers.begin(), monk_1_teachers.end());
	std::sort(monk_2_teachers.begin(), monk_2_teachers.end());
	std::set_intersection(
		monk_1_teachers.begin(), monk_1_teachers.end(),
		monk_2_teachers.begin(), monk_2_teachers.end(),
		back_inserter(same_teachers)
	);

	if (same_teachers.size() == 0) {
		std::cout << "У " << monk1 << " и " << monk2 << " нет общих учителей" << std::endl;
		return;
	}
	else if (same_teachers.size() == 1) {
		std::cout << monk1 << " и " << monk2 << " - оба монахи, и их общий учитель " << same_teachers.front();
	}
	else {
		std::cout << monk1 << " и " << monk2 << " - оба монахи, и их общий учитель " << same_teachers.back();
	}
}

/**
* Структура хранит в себе номер выбранной подпрограммы и её параметры.
*/
struct subProgrammChoice {
	int programm;
	std::vector<int> params;
};

/**
* Функция отвечает за то, какую подпрограмму выбирает пользователь.
*/
subProgrammChoice ChooseSubProgramm() {
	while (true)
	{
		std::cout << "Выберите жедаемую задачу (1 или 2): " << std::endl;
		std::string input;
		getline(std::cin, input);
		std::vector<std::string> splitted_input = SplitStrBySpace(input);
		std::vector<int> input_as_int = VecStrToVecInt(splitted_input);

		std::vector<int> params(input_as_int.begin() + 1, input_as_int.end());

		if (input_as_int[0] == 1) {
			if (params.size() != 1) {
				std::cerr << "ОШИБКА: Неверные аргументы подпрограммы" << std::endl;
				continue;
			}
			return { 1, params };
		}
		else if (input_as_int[0] == 2) {
			if (params.size() != 2) {
				std::cerr << "ОШИБКА: Неверные аргументы подпрограммы" << std::endl;
				continue;
			}
			return { 2, params };
		}
		else {
			std::cerr << "ОШИБКА: Неизвестная задача, попробуйте снова" << std::endl;
			continue;
		}
	}
}

int main()
{
	std::setlocale(LC_ALL, "ru_RU.UTF-8");

	std::unordered_map<student, teacher> monk_map;
	FillMonks(&monk_map); // Заполняет программу монахами
	subProgrammChoice pc = ChooseSubProgramm(); // Выбирает подпрограмму

	switch (pc.programm)
	{
	case 1:
		SubProgrammOne(monk_map, pc.params);
		break;
	case 2:
		SubProgrammTwo(monk_map, pc.params);
		break;
	default:
		break;
	}
	return 0;
}

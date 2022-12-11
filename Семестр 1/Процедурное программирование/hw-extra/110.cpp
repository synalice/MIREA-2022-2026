#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

typedef int teacher;
typedef int student;

std::vector<std::string> SplitInputBySpace(std::string str) {
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

bool InputIsValid(std::vector<std::string> input) {
	if (input.size() != 4) {
		std::cerr << "ОШИБКА: Неверное кол-во монахов" << std::endl;
		return false;
	}
	return true;
}

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

void FillMonks(std::unordered_map<student, teacher>* monk_map) {
	std::cout << "Введите исходные данные о монахах:" << std::endl;

	std::string input;
	while (true) {
		getline(std::cin, input);
		std::vector<std::string> splitted_input = SplitInputBySpace(input);
		if (InputIsValid(splitted_input) == false) {
			continue;
		}
		std::vector<int> monk_ID_s = VecStrToVecInt(splitted_input);

		for (int i = 0; i < monk_ID_s.size() - 1; i++) {
			if (monk_ID_s[i + 1] == 0) {
				continue;
			}
			monk_map->insert({ monk_ID_s[i + 1], monk_ID_s[0] });
		}

		if (monk_ID_s[0] == 1) {
			break;
		}
	}
}

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

void SubProgramOne(std::unordered_map<student, teacher> monk_map, std::vector<int> params) {
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

void SubProgramTwo(std::unordered_map<student, teacher> monk_map, std::vector<int> params) {
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

struct subProgramChoice {
	int program;
	std::vector<int> params;
};

subProgramChoice ChooseSubProgram() {
	while (true)
	{
		std::cout << "Выберите желаемую задачу (1 или 2): " << std::endl;
		std::string input;
		getline(std::cin, input);
		std::vector<std::string> splitted_input = SplitInputBySpace(input);
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
	std::unordered_map<student, teacher> monk_map;
	FillMonks(&monk_map);
	subProgramChoice pc = ChooseSubProgram();

	switch (pc.program)
	{
	case 1:
		SubProgramOne(monk_map, pc.params);
		break;
	case 2:
		SubProgramTwo(monk_map, pc.params);
		break;
	default:
		break;
	}
	return 0;
}

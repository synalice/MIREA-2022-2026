#include <iostream>
#include <string>
#include <unordered_map>
#include <clocale>

typedef int month;
typedef int days;

struct DayAndMonth {
    bool is_invalid;
    int day;
    int month;
};

bool StrIsNumber(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        ++it;
    return !str.empty() && it == str.end();
}

DayAndMonth ParseDayAndMonth(std::string str)
{
    DayAndMonth date {};

    constexpr int UNINITIALIZED = -1;

    int token_start = UNINITIALIZED;
    int token_end = UNINITIALIZED;

    int tokens_extracted = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '.') {
            if (token_start == UNINITIALIZED) {
                token_start = i;
                continue;
            }
        } else {
            token_end = i;
            if (token_start != UNINITIALIZED && token_end != UNINITIALIZED) {
                tokens_extracted++;
                std::string token = str.substr(token_start, token_end - token_start);
                if (tokens_extracted == 1) {
                    if (StrIsNumber(token)) {
                        date.day = stoi(token);
                    } else {
                        date.is_invalid = true;
                        return date;
                    }
                } else if (tokens_extracted == 2) {
                    if (StrIsNumber(token)) {
                        date.month = stoi(token);
                    } else {
                        date.is_invalid = true;
                        return date;
                    }
                }
                token_start = UNINITIALIZED;
                token_end = UNINITIALIZED;
            }
            token_end = UNINITIALIZED;
        }
    }

    if (token_start != UNINITIALIZED && token_end == UNINITIALIZED) {
        if (tokens_extracted == 1) {
            try {
                date.month = stoi(str.substr(token_start, str.size()));
            } catch (std::invalid_argument) {
                date.is_invalid = true;
                return date;
            }
        }
    }
    if (date.day == 0 || date.month == 0) {
        date.is_invalid = true;
    }
    return date;
}

std::unordered_map<month, days> InitCalendar()
{
    std::unordered_map<month, days> max_days_in_month;
    max_days_in_month.insert({ 1, 31 });
    max_days_in_month.insert({ 2, 29 });
    max_days_in_month.insert({ 3, 31 });
    max_days_in_month.insert({ 4, 30 });
    max_days_in_month.insert({ 5, 31 });
    max_days_in_month.insert({ 6, 30 });
    max_days_in_month.insert({ 7, 31 });
    max_days_in_month.insert({ 8, 31 });
    max_days_in_month.insert({ 9, 30 });
    max_days_in_month.insert({ 10, 31 });
    max_days_in_month.insert({ 11, 30 });
    max_days_in_month.insert({ 12, 31 });
    return max_days_in_month;
}

void ValidateDate(DayAndMonth& date)
{
    std::unordered_map<month, days> calendar = InitCalendar();

    if (date.day < 1) {
        date.is_invalid = true;
    } else if (12 < date.month || date.month < 1) {
        date.is_invalid = true;
    } else if (calendar.at(date.month) < date.day) {
        date.is_invalid = true;
    }
}

DayAndMonth GetDate()
{
    std::string input;
    while (true) {
        std::cout << "Введите дату: ";
        getline(std::cin, input);
        DayAndMonth date = ParseDayAndMonth(input);
        ValidateDate(date);
        if (date.is_invalid == true) {
            std::cerr << "ОШИБКА: Неверная дата" << std::endl;
            continue;
        } else {
            return date;
        }
    }
}

/**
 * Функция возвращает хэш-карту, заполненную описанным ниже способом.
 *
 * По условию задачи нам нужно найти в интервал какого знака зодиака входит
 * введенная пользователем дата. То есть нам нужно сравнить даты,
 * представленные в виде "день и месяц". По условию задачи интервалы знаков
 * зодиака следующие:
 *
 * 20.01-18.02: Водолей
 * 19.02-20.03: Рыбы
 * 21.03-19.04: Овен
 * 20.04-20.05: Телец
 * 21.05-21.06: Близнецы
 * 22.06-22.07: Рак
 * 23.07-22.08: Лев
 * 23.08-22.09: Дева
 * 23.09-22.10: Скорпион
 * 23.11-21.12: Стрелец
 * 22.12-19.01: Козерог
 *
 * Можно заметить, что если каждую из приведённых выше дат представить в виде
 * числа, в котором сначала идёт месяц, а затем день, то мы получим
 * следующие уникальные интервалы:
 *
 * 120-218: Водолей
 * 219-320: Рыбы
 * 321-419: Овен
 * 420-520: Телец
 * 521-621: Близнецы
 * 622-722: Рак
 * 723-822: Лев
 * 823-922: Дева
 * 923-1022: Скорпион
 * 1123-1221: Стрелец
 * 1222-119: Козерог
 *
 * Если мы представим введенную пользователем дату, например 27.09, таким же
 * образом, то сможем точно определить, что 927 относится к интервалу
 * 923-1022 и является знаком зодиака "Скорпион".
 *
 * Можно заметить, что возникает проблема в знаком "Козерог", у которого
 * происходит "переход через ноль" в плане месяца, из-за чего интервал
 * получается неверным. Это можно исправить следующим образом. Учитывая, что
 * программой предусмотрены проверки на верность введённой даты, пользователь
 * не сможет ввести неверную дату (например 32.12 или 0.01), мы можем
 * считать, что знак "Козерог" будет всегда, когда ВВОД пользователя БОЛЬШЕ,
 * чем 1222, ИЛИ когда ВВОД пользователя МЕНЬШЕ чем 119.
 */
std::unordered_map<std::string, std::pair<int, int>> InitZodiacs()
{
    std::unordered_map<std::string, std::pair<int, int>> zodiacs;
    zodiacs.insert({ "20.01-18.02: Водолей", { 120, 218 } });
    zodiacs.insert({ "19.02-20.03: Рыбы", { 219, 320 } });
    zodiacs.insert({ "21.03-19.04: Овен", { 321, 419 } });
    zodiacs.insert({ "20.04-20.05: Телец", { 420, 520 } });
    zodiacs.insert({ "21.05-21.06: Близнецы", { 521, 621 } });
    zodiacs.insert({ "22.06-22.07: Рак", { 622, 722 } });
    zodiacs.insert({ "23.07-22.08: Лев", { 723, 822 } });
    zodiacs.insert({ "23.08-22.09: Дева", { 823, 922 } });
    zodiacs.insert({ "23.09-22.10: Скорпион", { 923, 1022 } });
    zodiacs.insert({ "23.11-21.12: Стрелец", { 1123, 1221 } });
    zodiacs.insert({ "22.12-19.01: Козерог", { 1222, 119 } });
    return zodiacs;
}

int DateAsInt(DayAndMonth date)
{
    return std::stoi(std::to_string(date.month) + std::to_string(date.day));
}

void FindZodiac(DayAndMonth date)
{
    std::unordered_map<std::string, std::pair<int, int>> zodiacs = InitZodiacs();
    int dateInt = DateAsInt(date);
    if (dateInt >= 1222 || dateInt <= 119) {
        std::cout << "22.12-19.01: Козерог\n";
        return;
    }
    for (auto& it : zodiacs) {
        if (it.second.first <= dateInt && it.second.second >= dateInt) {
            std::cout << it.first << "\n";
            break;
        }
    }
}

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    while (true) {
        DayAndMonth date = GetDate();
        FindZodiac(date);
    }

    return 0;
}

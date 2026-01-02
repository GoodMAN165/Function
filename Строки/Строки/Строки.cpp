#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Реверс строки

// Вариант 1: С использованием алгоритма reverse
string reverseWithAlgorithm(string str) {
    string result = str;
    reverse(result.begin(), result.end());
    return result;
}

// Вариант 2: Без использования алгоритма (цикл)
string reverseWithLoop(string str) {
    string result = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        result += str[i];
    }
    return result;
}

void task1() {
    cout << "Задание 1: Реверс строки\n";

    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    cout << "\nВариант 1 (с алгоритмом reverse):\n";
    cout << "Результат: " << reverseWithAlgorithm(input) << endl;

    cout << "\nВариант 2 (с циклом):\n";
    cout << "Результат: " << reverseWithLoop(input) << endl;
}

// Подсчет символов

// Структура для хранения результатов подсчета
struct CharCount {
    int letters;
    int digits;
    int spaces;
    int others;
};

// Функция подсчета символов
CharCount countCharacters(string str) {
    CharCount result = { 0, 0, 0, 0 };

    for (char c : str) {
        if (isalpha(c)) {  // буква (английская)
            result.letters++;
        }
        else if (c >= 'а' && c <= 'я') {  // русская буква (строчная)
            result.letters++;
        }
        else if (c >= 'А' && c <= 'Я') {  // русская буква (заглавная)
            result.letters++;
        }
        else if (isdigit(c)) {  // цифра
            result.digits++;
        }
        else if (isspace(c)) {  // пробельный символ
            result.spaces++;
        }
        else {  // другие символы
            result.others++;
        }
    }

    return result;
}

void task2() {
    cout << "\nЗадание 2: Подсчет символов\n";

    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    CharCount counts = countCharacters(input);

    cout << "\nРезультаты подсчета:\n";
    cout << "Букв: " << counts.letters << endl;
    cout << "Цифр: " << counts.digits << endl;
    cout << "Пробельных символов: " << counts.spaces << endl;
    cout << "Других символов: " << counts.others << endl;
    cout << "Всего символов: " << input.length() << endl;
}

//Удаление дубликатов

// Функция удаления дубликатов с сохранением порядка
string removeDuplicates(string str) {
    string result = "";
    bool seen[256] = { false };  // для ASCII символов

    for (char c : str) {
        // Преобразуем символ в индекс массива
        unsigned char idx = c;

        // Если символ еще не встречался
        if (!seen[idx]) {
            result += c;
            seen[idx] = true;
        }
    }

    return result;
}

// Альтернативный вариант без массива фиксированного размера
string removeDuplicatesAlternative(string str) {
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        // Проверяем, встречался ли символ ранее в строке
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                found = true;
                break;
            }
        }

        // Если символ не встречался ранее, добавляем его
        if (!found) {
            result += str[i];
        }
    }

    return result;
}

void task3() {
    cout << "\nЗадание 3: Удаление дубликатов\n";

    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    string result1 = removeDuplicates(input);
    string result2 = removeDuplicatesAlternative(input);

    cout << "\nВариант 1 (с использованием массива):\n";
    cout << "Результат: " << result1 << endl;

    cout << "\nВариант 2 (с двойным циклом):\n";
    cout << "Результат: " << result2 << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        cout << "1. Реверс строки\n";
        cout << "2. Подсчет символов\n";
        cout << "3. Удаление дубликатов\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;
        cin.ignore();  // очищаем буфер ввода

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}
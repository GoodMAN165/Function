#include <iostream>

using namespace std;

// Функция выводит на экран прямоугольник из звёздочек (*)
void rectangle(int& Height, int& Width) {
    for (int i = 0; i < Height; i++) {
        for (int j = 0; j < Width; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Функция вычисляет факториал числа x
int factorial(int& number) {
    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

// Функция проверяет, является ли число x простым
bool isPrime(int& number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Функция возвращает куб числа x (x³)
int cube(int& number) {
    return number * number * number;
}

// Функция возвращает наибольшее из двух целых чисел
int maxOfTwo(int& num1, int& num2) {
    return (num1 > num2) ? num1 : num2;
}

// Функция проверяет, является ли число x положительным
bool isPositive(int& number) {
    return number > 0;
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a, b = 0;
    short choice;
    cout << "Функции";
    cout << "\n\
    Выберите желаемое действие: \n\
    1 - Вывод прямоугольника \n\
    2 - Вычисление факториала \n\
    3 - Простое число \n\
    4 - Куб числа \n\
    5 - Наибольшее \n\
    6 - Положительное и отрицательное \n";

    cout << "Введите код действия: "; cin >> choice;

    switch (choice) {
    case 1:

        cout << "Введите желаемую высоту и ширину прямоугольника: "; cin >> a >> b;
        rectangle(a, b);
        break;

    case 2:

        cout << "Введите желаемое число для нахождения факториала: "; cin >> a;
        factorial(a);
        break;

    case 3:

        cout << "Введите желаемое число для проверки: "; cin >> a;
        isPrime(a);
        break;

    case 4:

        cout << "Введите желаемое число для возведения его в куб"; cin >> a;
        cube(a);
        break;

    case 5:

        cout << "Введите любых два числа для сравнения их: "; cin >> a >> b;
        maxOfTwo(a, b);
        break;

    case 6:

        cout << "Введите желаемое число для проверки: "; cin >> a;
        isPositive(a);
        break;

    default:
        return 0;
    }
    
    return 0;
}

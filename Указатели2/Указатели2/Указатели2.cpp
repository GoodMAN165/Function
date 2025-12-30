#include <iostream>
using namespace std;

// Копирование массива через указатели

void task1() {
    const int SIZE = 5;
    int source[SIZE] = { 10, 20, 30, 40, 50 };
    int destination[SIZE];

    int* srcPtr = source;      // указатель на начало исходного массива
    int* dstPtr = destination; // указатель на начало целевого массива

    cout << "Копирование массива\n";
    cout << "Исходный массив:  ";

    // Копируем элементы
    for (int i = 0; i < SIZE; i++) {
        *(dstPtr + i) = *(srcPtr + i); // разыменование и копирование
    }

    // Выводим исходный массив
    for (int i = 0; i < SIZE; i++) {
        cout << *(srcPtr + i) << " ";
    }

    cout << "\nСкопированный массив: ";

    // Выводим скопированный массив
    for (int i = 0; i < SIZE; i++) {
        cout << *(dstPtr + i) << " ";
    }
    cout << endl;
}

// Реверс массива через указатели
void task2() {
    const int SIZE = 6;
    int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };

    int* start = arr;                 // указатель на начало массива
    int* end = arr + SIZE - 1;        // указатель на конец массива

    cout << "\nРеверс массива\n";
    cout << "Исходный массив:  ";

    for (int i = 0; i < SIZE; i++) {
        cout << *(start + i) << " ";
    }

    // Меняем элементы местами
    while (start < end) {
        int temp = *start;   // сохраняем значение через разыменование
        *start = *end;       // меняем местами
        *end = temp;

        start++;  // продвигаемся вперед
        end--;    // продвигаемся назад
    }

    cout << "\nРеверсированный массив: ";

    // Выводим результат
    int* ptr = arr;
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// Копирование с реверсом
void task3() {
    const int SIZE = 5;
    int source[SIZE] = { 100, 200, 300, 400, 500 };
    int destination[SIZE];

    int* srcPtr = source;                 // указатель на начало исходного массива
    int* dstPtr = destination + SIZE - 1; // указатель на конец целевого массива

    cout << "\nКопирование с реверсом\n";
    cout << "Исходный массив:  ";

    for (int i = 0; i < SIZE; i++) {
        cout << *(srcPtr + i) << " ";
    }

    // Копируем в обратном порядке
    for (int i = 0; i < SIZE; i++) {
        *dstPtr = *(srcPtr + i); // копируем текущий элемент исходного в конец целевого
        dstPtr--;                // двигаемся назад по целевому массиву
    }

    cout << "\nРеверсированная копия: ";

    // Выводим результат
    int* ptr = destination;
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    do {
        cout << "\nРабота с указателями\n";
        cout << "1. Копирование массива\n";
        cout << "2. Реверс массива\n";
        cout << "3. Копирование с реверсом\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;

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
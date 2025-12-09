#include <iostream>
#include <algorithm> // Для функции sort
#include <vector>    // Для использования векторов
using namespace std;

// Функция специальной сортировки
void customSort(int arr[], int n) {
    // Векторы для хранения элементов на четных и нечетных позициях
    vector<int> oddPos;  // Нечетные позиции (1, 3, 5...)
    vector<int> evenPos; // Четные позиции (0, 2, 4...)

    // Разделяем элементы по позициям
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenPos.push_back(arr[i]); // Четные индексы
        }
        else {
            oddPos.push_back(arr[i]);  // Нечетные индексы
        }
    }

    // Сортируем нечетные позиции по возрастанию
    sort(oddPos.begin(), oddPos.end());
    // Сортируем четные позиции по убыванию
    sort(evenPos.begin(), evenPos.end(), greater<int>());

    // Собираем массив обратно
    int oddIdx = 0, evenIdx = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] = evenPos[evenIdx++]; // Четные позиции из вектора evenPos
        }
        else {
            arr[i] = oddPos[oddIdx++];   // Нечетные позиции из вектора oddPos
        }
    }
}

// Функция вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    // Применяем специальную сортировку
    customSort(arr, n);

    cout << "После сортировки (четные↓, нечетные↑): ";
    printArray(arr, n);

    return 0;
}
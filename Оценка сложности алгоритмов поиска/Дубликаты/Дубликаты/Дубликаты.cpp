#include <iostream>
using namespace std;

// Функция удаления дубликатов из массива
int removeDuplicates(int arr[], int n) {
    // Если массив пуст, возвращаем 0
    if (n == 0) return 0;

    int uniqueIndex = 0; // Индекс для уникальных элементов

    // Проходим по всем элементам массива
    for (int i = 1; i < n; i++) {
        bool isDuplicate = false;

        // Проверяем, встречался ли текущий элемент ранее
        for (int j = 0; j <= uniqueIndex; j++) {
            if (arr[j] == arr[i]) {
                isDuplicate = true; // Элемент уже есть
                break;
            }
        }

        // Если элемент не дубликат, добавляем его
        if (!isDuplicate) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    // Возвращаем новую длину массива
    return uniqueIndex + 1;
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

    int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    // Удаляем дубликаты и получаем новую длину
    int newSize = removeDuplicates(arr, n);

    cout << "Без дубликатов: ";
    printArray(arr, newSize);
    cout << "Новая длина: " << newSize << endl;

    return 0;
}
#include <iostream>
using namespace std;

// Проверка, отсортирован ли массив по убыванию
bool isSortedDesc(int arr[], int n) {
    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        // Если следующий элемент больше текущего, массив не упорядочен по убыванию
        if (arr[i] < arr[i + 1]) {
            return false; // Нарушен порядок
        }
    }
    return true; // Все элементы упорядочены по убыванию
}

// Функция пузырьковой сортировки по убыванию
void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Используем стандартную функцию swap для замены элементов
                swap(arr[j], arr[j + 1]);
            }
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

    // Уже упорядоченный по убыванию массив
    int arr[] = { 90, 64, 34, 25, 22, 12, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    // Проверяем, упорядочен ли массив по убыванию
    if (isSortedDesc(arr, n)) {
        cout << "Массив упорядочен по убыванию." << endl;
    }
    else {
        cout << "Массив не упорядочен по убыванию. Сортируем..." << endl;
        // Сортируем массив
        bubbleSortDesc(arr, n);
        cout << "Отсортированный массив: ";
        printArray(arr, n);
    }

    return 0;
}
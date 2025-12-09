#include <iostream>
using namespace std;

// Функция пузырьковой сортировки по убыванию
void bubbleSortDesc(int arr[], int n) {
    // Внешний цикл: количество проходов
    for (int i = 0; i < n - 1; i++) {
        // Внутренний цикл: сравнение соседних элементов
        for (int j = 0; j < n - i - 1; j++) {
            // Если текущий элемент меньше следующего, меняем местами
            if (arr[j] < arr[j + 1]) {
                // Меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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

    // Исходный массив
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]); // Вычисляем размер массива

    cout << "Исходный массив: ";
    printArray(arr, n);

    // Вызов функции сортировки по убыванию
    bubbleSortDesc(arr, n);

    cout << "Отсортированный по убыванию: ";
    printArray(arr, n);

    return 0;
}
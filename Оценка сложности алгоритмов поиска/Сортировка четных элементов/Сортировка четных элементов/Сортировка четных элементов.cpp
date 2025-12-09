#include <iostream>
using namespace std;

// Сортировка четных элементов массива (по индексам) пузырьком по убыванию
void sortEvenElements(int arr[], int n) {
    // Сортируем только элементы с четными индексами (0, 2, 4...)
    for (int i = 0; i < n; i += 2) {
        // Внутренний цикл также проходит только по четным индексам
        for (int j = 0; j < n - i - 2; j += 2) {
            // Сравниваем элементы на четных позициях
            if (arr[j] < arr[j + 2]) {
                // Меняем местами, если порядок нарушен
                swap(arr[j], arr[j + 2]);
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

    // Тестовый массив
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Исходный массив: ";
    printArray(arr, n);
    
    // Сортируем четные элементы
    sortEvenElements(arr, n);
    
    cout << "После сортировки четных элементов: ";
    printArray(arr, n);
    
    return 0;
}
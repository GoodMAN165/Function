#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Телефонный справочник
void task1() {
    const int n = 5;
    int mobTel[n], tel[n];
    bool isDataEntered = false;
    int userChoice;

    do {
        cout << "\nТелефонный справочник\n";
        cout << "1. Ввести данные\n";
        cout << "2. Вывести данные\n";
        cout << "3. Сортировать по мобильным номерам\n";
        cout << "4. Сортировать по домашним номерам\n";
        cout << "5. Выход\n";
        cout << "Выберите пункт: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1: // Ввод данных
            cout << "Введите данные для " << n << " пользователей:\n";
            for (int i = 0; i < n; i++) {
                cout << "Пользователь " << i + 1 << ":\n";
                cout << "  Мобильный: ";
                cin >> mobTel[i];
                cout << "  Домашний: ";
                cin >> tel[i];
            }
            isDataEntered = true;
            cout << "Данные сохранены.\n";
            break;

        case 2: // Вывод данных
            if (!isDataEntered) {
                cout << "Данные не введены! Сначала выберите пункт 1.\n";
                break;
            }
            cout << "\nСписок пользователей:\n";
            cout << "№\tМобильный\tДомашний\n";
            for (int i = 0; i < n; i++) {
                cout << i + 1 << "\t" << mobTel[i] << "\t\t" << tel[i] << endl;
            }
            break;

        case 3: // Сортировка по мобильным номерам
            if (!isDataEntered) {
                cout << "Данные не введены!\n";
                break;
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (mobTel[j] > mobTel[j + 1]) {
                        swap(mobTel[j], mobTel[j + 1]);
                        swap(tel[j], tel[j + 1]);
                    }
                }
            }
            cout << "Сортировка по мобильным номерам выполнена.\n";
            break;

        case 4: // Сортировка по домашним номерам
            if (!isDataEntered) {
                cout << "Данные не введены!\n";
                break;
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (tel[j] > tel[j + 1]) {
                        swap(tel[j], tel[j + 1]);
                        swap(mobTel[j], mobTel[j + 1]);
                    }
                }
            }
            cout << "Сортировка по домашним номерам выполнена.\n";
            break;

        case 5:
            cout << "Выход из справочника.\n";
            break;

        default:
            cout << "Неверный пункт меню!\n";
        }
    } while (userChoice != 5);
}


// Улучшенная пузырьковая сортировка
void improvedBubbleSort(int arr[], int n, int& swapCount) {
    for (int i = 0; i < n - 1; i++) {
        swapCount = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
        if (swapCount == 0) {
            cout << "Массив отсортирован досрочно на шаге " << i + 1 << endl;
            break;
        }
    }
}

void task2() {
    const int n = 10;
    int arr[n];
    int swapCount = 0;

    cout << "\nУлучшеная сортировка пузырьком\n";
    cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    improvedBubbleSort(arr, n, swapCount);

    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Количество перестановок: " << swapCount << endl;
}


// Сравнение пузырьковой и выбором
void selectionSort(int arr[], int n, int& swapCount) {
    swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++;
        }
    }
}

void task4() {
    const int SIZE = 1000;
    const int TESTS = 10;
    int bubbleSwaps = 0, selectionSwaps = 0;
    srand(time(0));

    cout << "\nСравнение сортировок\n";
    cout << "Тестирование на " << TESTS << " массивах по " << SIZE << " элементов...\n";

    for (int t = 0; t < TESTS; t++) {
        int arr1[SIZE], arr2[SIZE];
        for (int i = 0; i < SIZE; i++) {
            arr1[i] = arr2[i] = rand() % 10000;
        }

        int bubbleCount = 0, selectionCount = 0;

        // Пузырьковая сортировка
        for (int i = 0; i < SIZE - 1; i++) {
            int swaps = 0;
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr1[j] > arr1[j + 1]) {
                    swap(arr1[j], arr1[j + 1]);
                    swaps++;
                }
            }
            bubbleCount += swaps;
            if (swaps == 0) break;
        }

        // Сортировка выбором
        selectionSort(arr2, SIZE, selectionCount);

        bubbleSwaps += bubbleCount;
        selectionSwaps += selectionCount;
    }

    cout << "Среднее число перестановок:\n";
    cout << "Пузырьковая: " << bubbleSwaps / TESTS << endl;
    cout << "Выбором: " << selectionSwaps / TESTS << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice;

    do {
        cout << "\nГлавное меню\n";
        cout << "1. Телефонный справочник (Задание 1)\n";
        cout << "2. Улучшенная пузырьковая сортировка (Задание 2)\n";
        cout << "4. Сравнение сортировок (Задание 4)\n";
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
        case 4:
            task4();
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
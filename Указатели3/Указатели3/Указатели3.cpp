#include <iostream>
#include <cmath>
using namespace std;

//Вспомогательные функции

// Проверка, содержится ли элемент в массиве
bool contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}

// Проверка на простое число
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Элементы A, которых нет в B
void task1_DZ1() {
    cout << "\nЗадание 1 (ДЗ1)\n";

    int M, N;
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Временный массив для результата (максимальный возможный размер)
    int* temp = new int[M];
    int tempSize = 0;

    // Собираем элементы A, которых нет в B, без повторений
    for (int i = 0; i < M; i++) {
        // Проверяем, что элемента нет в B и он еще не добавлен в результат
        if (!contains(B, N, A[i]) && !contains(temp, tempSize, A[i])) {
            temp[tempSize++] = A[i];
        }
    }

    // Создаем финальный массив минимального размера
    int* result = new int[tempSize];
    for (int i = 0; i < tempSize; i++) {
        result[i] = temp[i];
    }

    cout << "Результат (элементы A, которых нет в B):\n";
    for (int i = 0; i < tempSize; i++) {
        cout << result[i] << " ";
    }
    cout << "\nРазмер результата: " << tempSize << endl;

    delete[] A;
    delete[] B;
    delete[] temp;
    delete[] result;
}

// Элементы, не являющиеся общими
void task2_DZ1() {
    cout << "\nЗадание 2 (ДЗ1)\n";

    int M, N;
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Временный массив для результата
    int* temp = new int[M + N];
    int tempSize = 0;

    // Элементы из A, которых нет в B
    for (int i = 0; i < M; i++) {
        if (!contains(B, N, A[i]) && !contains(temp, tempSize, A[i])) {
            temp[tempSize++] = A[i];
        }
    }

    // Элементы из B, которых нет в A
    for (int i = 0; i < N; i++) {
        if (!contains(A, M, B[i]) && !contains(temp, tempSize, B[i])) {
            temp[tempSize++] = B[i];
        }
    }

    // Создаем финальный массив минимального размера
    int* result = new int[tempSize];
    for (int i = 0; i < tempSize; i++) {
        result[i] = temp[i];
    }

    cout << "Результат (элементы, не являющиеся общими):\n";
    for (int i = 0; i < tempSize; i++) {
        cout << result[i] << " ";
    }
    cout << "\nРазмер результата: " << tempSize << endl;

    delete[] A;
    delete[] B;
    delete[] temp;
    delete[] result;
}

// Работа с динамическими массивами

// 1. Функция распределения динамической памяти
int* allocateArray(int size) {
    return new int[size];
}

// 2. Функция инициализации динамического массива
void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // случайные числа от 0 до 99
    }
}

// 3. Функция печати динамического массива
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 4. Функция удаления динамического массива
void deleteArray(int* arr) {
    delete[] arr;
}

// 5. Функция добавления элемента в конец массива
int* addToEnd(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];

    // Копируем старые элементы
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    // Добавляем новый элемент
    newArr[size] = value;
    size++;

    delete[] arr;  // удаляем старый массив
    return newArr;
}

// 6. Функция вставки элемента по указанному индексу
int* insertAtIndex(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Неверный индекс!\n";
        return arr;
    }

    int* newArr = new int[size + 1];

    // Копируем элементы до индекса
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    // Вставляем новый элемент
    newArr[index] = value;

    // Копируем элементы после индекса
    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    size++;
    delete[] arr;  // удаляем старый массив
    return newArr;
}

// 7. Функция удаления элемента по указанному индексу
int* removeAtIndex(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!\n";
        return arr;
    }

    int* newArr = new int[size - 1];

    // Копируем элементы до индекса
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    // Копируем элементы после индекса
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    size--;
    delete[] arr;  // удаляем старый массив
    return newArr;
}

// Тестирование функций динамического массива
void task1_DZ2() {
    cout << "\nЗадание 1 (ДЗ2)\n";

    int size = 5;
    int* arr = allocateArray(size);

    cout << "1. Инициализация массива:\n";
    initializeArray(arr, size);
    cout << "Массив: ";
    printArray(arr, size);

    cout << "\n2. Добавление элемента 99 в конец:\n";
    arr = addToEnd(arr, size, 99);
    cout << "Массив: ";
    printArray(arr, size);

    cout << "\n3. Вставка элемента 50 по индексу 2:\n";
    arr = insertAtIndex(arr, size, 2, 50);
    cout << "Массив: ";
    printArray(arr, size);

    cout << "\n4. Удаление элемента по индексу 3:\n";
    arr = removeAtIndex(arr, size, 3);
    cout << "Массив: ";
    printArray(arr, size);

    cout << "\n5. Удаление массива\n";
    deleteArray(arr);
}

// Удаление простых чисел
int* removePrimes(int* arr, int size, int& newSize) {
    // Сначала считаем, сколько непростых чисел
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    // Создаем новый массив
    int* newArr = new int[newSize];
    int index = 0;

    // Копируем только непростые числа
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[index++] = arr[i];
        }
    }

    return newArr;
}

void task2_DZ2() {
    cout << "\nЗадание 2 (ДЗ2)\n";

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = allocateArray(size);

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    printArray(arr, size);

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    cout << "Массив без простых чисел: ";
    printArray(newArr, newSize);

    deleteArray(arr);
    deleteArray(newArr);
}

// Распределение элементов по знаку
void separateArray(int* staticArr, int size, int*& positiveArr, int& posSize,
    int*& negativeArr, int& negSize, int*& zeroArr, int& zeroSize) {

    // Сначала считаем количество элементов каждого типа
    posSize = negSize = zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) posSize++;
        else if (staticArr[i] < 0) negSize++;
        else zeroSize++;
    }

    // Выделяем память
    positiveArr = new int[posSize];
    negativeArr = new int[negSize];
    zeroArr = new int[zeroSize];

    // Заполняем массивы
    int posIdx = 0, negIdx = 0, zeroIdx = 0;

    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) {
            positiveArr[posIdx++] = staticArr[i];
        }
        else if (staticArr[i] < 0) {
            negativeArr[negIdx++] = staticArr[i];
        }
        else {
            zeroArr[zeroIdx++] = staticArr[i];
        }
    }
}

void task3_DZ2() {
    cout << "\nЗадание 3 (ДЗ2)\n";

    int size;
    cout << "Введите размер статического массива: ";
    cin >> size;

    int* staticArr = new int[size];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> staticArr[i];
    }

    cout << "Исходный массив: ";
    printArray(staticArr, size);

    int* positiveArr, * negativeArr, * zeroArr;
    int posSize, negSize, zeroSize;

    separateArray(staticArr, size, positiveArr, posSize, negativeArr, negSize, zeroArr, zeroSize);

    cout << "Положительные элементы: ";
    printArray(positiveArr, posSize);

    cout << "Отрицательные элементы: ";
    printArray(negativeArr, negSize);

    cout << "Нулевые элементы: ";
    printArray(zeroArr, zeroSize);

    delete[] staticArr;
    delete[] positiveArr;
    delete[] negativeArr;
    delete[] zeroArr;
}

// Главное меню
int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int choice;

    do {
        cout << "ДЗ 1\n";
        cout << "1. Элементы A, которых нет в B\n";
        cout << "2. Элементы, не являющиеся общими\n";
        cout << "\nДЗ 2 2\n";
        cout << "3. Функции для работы с динамическим массивом\n";
        cout << "4. Удаление простых чисел\n";
        cout << "5. Распределение элементов по знаку\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;

        switch (choice) {
        case 1:
            task1_DZ1();
            break;
        case 2:
            task2_DZ1();
            break;
        case 3:
            task1_DZ2();
            break;
        case 4:
            task2_DZ2();
            break;
        case 5:
            task3_DZ2();
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
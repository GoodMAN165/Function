#include <iostream>

using namespace std;

void func1(int* c, int* d) {
    
    if (*c > *d) {
        cout << *c << " больше " << *d << endl;
    }
    else {
        cout << *d << " больше " << *c << endl;
    }
}

void func2(int* c) {
    
    if (*c > 0) {
        cout << *c << " положительное" << endl;
    }
    else {
        cout << *c << " отрицательное" << endl;
    }
}

void func3(int* c, int* d) {
    
    int skip = *c;
    *c = *d;
    *d = skip;

    cout << *c << " " << *d << " " << skip << endl;
}

int calc(int* c, int* d) {
    
    short input;

    cout << "\n\
    Выберите действие: \n\
    1 = + \n\
    2 = - \n\
    3 = / \n\
    4 = * \n";

    cin >> input;

    switch (input) {
    case 1:
        return *c + *d;
    case 2:
        return *c - *d;
    case 3:
        return *c / *d;
    case 4:
        return *c * *d;
    default:
        cout << "Такого действия нет в списке!";
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    int a;
    int b;
    short userInput;

    cout << "Функции" << endl;

    cout << "\n\
    Выберите действие: \n\
    1 - наибольшее \n\
    2 - знак числа \n\
    3 - смена значений \n\
    4 - калькулятор \n";

    cin >> userInput;

    switch(userInput) {
    case 1:
        cout << "Введите два любых числа: "; cin >> a >> b;
        func1(&a, &b);
        break;
    case 2:
        cout << "Введите одно любое число: "; cin >> a;
        func2(&a);
        break;
    case 3:
        cout << "Введите два любых числа: "; cin >> a >> b;
        func3(&a, &b);
        break;
    case 4:
        cout << "Введите два любых числа: "; cin >> a >> b;
        calc(&a, &b);
        break;
    default:
        cout << "Такого действия нет в списке!";
    }
    return 0;
}

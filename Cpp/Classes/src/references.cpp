#include <iostream>

using namespace std;

int main() {
    int number = 5;

    int &refNumber = number;
    cout << refNumber << endl; // 5

    refNumber = 20;
    cout << number << endl; // 20

    int value1 = 10;
    int value2 = 6;

    int *ptr = nullptr; // Нулевой указатель
    int *&ptrRef = ptr; // Ссылка на указатель

    ptrRef = &value1;                       // Через ссылку указателю ptr присваивается адрес переменной value1
    cout << "ptr value = " << *ptr << endl; // 10

    *ptrRef = 70;                                // Изменяем значение по адресу, на который указывает указатель
    cout << "value1 value = " << value1 << endl; // 70

    ptrRef = &value2;                     // Изменяем адрес, на который указывает указатель
    cout << "p value = " << *ptr << endl; // 6

    return 0;
}
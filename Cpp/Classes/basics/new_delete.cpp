#include <iostream>

using namespace std;

int main() {

    int dynamicArrayLength = 10;
    int *dynamicArray = new int[dynamicArrayLength]; // аллоцировали память
    delete[] dynamicArray;                           // освободили память

    int rows = 3;
    int cols = 7;
    int **arr = new int *[rows]; // динамический двумерный массив
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }

    // Освобождение памяти под двумерный массив
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
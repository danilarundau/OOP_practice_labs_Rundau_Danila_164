#include <iostream>
#include <locale>
int main() {
    setlocale(LC_ALL, "russian");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int* ptr = arr;
    int max = *ptr;

    for (int i = 1; i < size; ++i) {
        ptr++;
        if (*ptr > max) {
            max = *ptr;
        }
    }

    std::cout << "Максимальный элемент: " << max << std::endl;

    delete[] arr;
    return 0;
}

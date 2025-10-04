#include <iostream>
#include <locale>
using namespace std;
void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    setlocale(LC_ALL, "russian");
    int num1, num2;

    cout << "Введите первое целое число: ";
    cin >> num1;

    cout << "Введите второе целое число: ";
    cin >> num2;

    cout << "До обмена:" << endl;
    cout << "Первое число: " << num1 << endl;
    cout << "Второе число: " << num2 << endl;

    swapNumbers(&num1, &num2);

    cout << "\nПосле обмена:" << endl;
    cout << "Первое число: " << num1 << endl;
    cout << "Второе число: " << num2 << endl;

    return 0;

   

}

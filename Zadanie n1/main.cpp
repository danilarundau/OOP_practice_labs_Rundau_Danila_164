#include <iostream>
#include <locale>
using namespace std;


int main()
{
    setlocale(LC_ALL, "russian");
    cout << "Введите целое число : ";
    int x;
    cin >> x;
    if (x % 2 == 0)
        cout << "Введенное число четное " << x;
    else
        cout << "Введенное число нечетное " << x;
    return 0;
}

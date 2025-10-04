#include <iostream>
#include <vector>
#include<locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    cout << "Сумма положительных элементов: " << sum << endl;

    return 0;
}

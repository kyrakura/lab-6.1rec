#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;
//Рекурсивний спосіб

const int N = 25;

void Create(int a[], const int size, const int Low, const int High, int i) {
    if (i == size) {
        return;
    }
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

void Print(int a[], const int size, int i) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    Print(a, size, i + 1);
}

int Count(int a[], const int size, int i) {
    if (i == size) {
        return 0;
    }
    int count = Count(a, size, i + 1);
    if (a[i] < 0 && i % 3 != 0) {
        return count + 1;
    }
    return count;
}

int Sum(int a[], const int size, int i) {
    if (i == size) {
        return 0;
    }
    int sum = Sum(a, size, i + 1);
    if (a[i] < 0 && i % 3 != 0) {
        return sum + a[i];
    }
    return sum;
}

void Replace(int a[], const int size, int i) {
    if (i == size) {
        return;
    }
    if (a[i] < 0 && i % 3 != 0) {
        a[i] = 0;
    }
    Replace(a, size, i + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));
    int a[N];
    int Low = -11;
    int High = 13;

    Create(a, N, Low, High, 0);

    cout << "Початковий масив: ";
    Print(a, N, 0);

    int count = Count(a, N, 0);
    int sum = Sum(a, N, 0);

    cout << "Кількість від'ємних елементів, крім кратних 3: " << count << endl;
    cout << "Сума від'ємних елементів, крім кратних 3: " << sum << endl;

    Replace(a, N, 0);

    cout << "Модифікований масив: ";
    Print(a, N, 0);

    return 0;
}

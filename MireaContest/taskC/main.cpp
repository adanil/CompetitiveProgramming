#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


void Print(int *a, int n)  // вывод перестановки
{
    static int num = 1; // номер перестановки
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            cout << 'b';
        else
            cout << 'a';
    }
    cout << endl;
}


void swap(int *a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool NextSet(int *a, int n);
int main() {
    int n;
    cin >> n;
    int *a;
    n = pow(2,n);
    a = new int[n];
    for (int i = 0;i < n/2;i++){
        a[i] = 0;
    }
    for (int i = n/2;i < n;i++){
        a[i] = 1;
    }
    Print(a, n);
    int t = 0;
    while (NextSet(a, n) && t < (n-1)) {
        Print(a, n);
        t++;
    }
    return 0;

    return 0;
}

bool NextSet(int *a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l<r)
        swap(a, l++, r--);
    return true;
}


/*
 * 2
 * aabb
 * bbaa
 * abab
 * abba
 */
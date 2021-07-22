#include <iostream>
#include <string>
#include <random>
#include <cstdlib>

using namespace std;
using ll = long long;



int main() {
    srand(time(NULL)); // устанавливаем стартовое значение - 4 541
    int good = 0;
    // Выводим 100 случайных чисел
    for (int t = 0;t < 1000000000;t++) {
        int s = 0;
        for (int count = 0; count < 6; ++count) {
            int k = rand() % 6 + 9;
//            std::cout << k << " ";
            s += k;

        }
        if (s == 63)
            good++;
//        cout << endl;
    }
    cout << (double)good/1000000000.0 << endl;
    return 0;
}
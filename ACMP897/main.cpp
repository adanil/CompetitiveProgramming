#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (long long i = 0; i < n;i++){
        bool  fl = false;
        for (long long j = 2;j <= sqrt(a[i]);j++){
            long long k = a[i];
            while (k % j == 0){
                k /= j;
            }
            if (k == 1 && !fl) {
                cout << "YES" << endl;
                fl = true;
            }
        }
        if (!fl)
            cout << "NO" << endl;
    }

    return 0;
}
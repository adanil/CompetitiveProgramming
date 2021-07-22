#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long totalKek = 0;
    if (n%2 != 0) {
        for (int i = 0; i < n; i++) {
            if ((n - i) % 2 != 0)
                totalKek ^= arr[i];
            //totalKek ^= currKek;
        }
    }
    cout << totalKek << endl;


    return 0;
}
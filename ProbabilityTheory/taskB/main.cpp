#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {

    double ans = 0;
    int n;
    cin >> n;
    int t = 0;
    for (int i = 0;i < n;i++){
        int a;
        cin >> a;
        if (a != i+1)
            t++;
    }
    for (int i = 1;i < t+1;i++){
        ans += i * (1/(double)t);
    }
    cout << t << endl;
    return 0;
}
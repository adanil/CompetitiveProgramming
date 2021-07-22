#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 1;i <= n;i++){
        sum += i;
    }

    vector<int> s1;
    vector<int> s2;
    ll curSum = 0;
    for (int i = 1;i < sum + 1/2;i++){
        if (gcd(i,sum - i) > 1){
            cout << "YES" << endl;
            for (int j = n;j >= 1;j--) {
                if (curSum + j <= i) {
                    curSum += j;
                    s1.push_back(j);
                } else{
                    s2.push_back(j);
                }
            }
            cout << s1.size() << ' ';
            for (auto el : s1)
                cout << el << ' ';
            cout << endl;
            cout << s2.size() << ' ';
            for (auto el : s2)
                cout << el << ' ';
            cout << endl;

            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
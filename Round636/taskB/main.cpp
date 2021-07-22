#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if ((n / 2)%2  == 1){
            cout << "NO" << endl;
            continue;
        }
        vector<ll> ans(n);
        ll chet = 2;
        ll chetSum = 0;
        for (int i = 0;i < n/2;i++){
            chetSum += chet;
            ans[i] = chet;
            chet += 2;
        }
        ll nechet = 1;
        ll nechetSum = 0;
        for (int i = n/2;i < n-1;i++){
            nechetSum += nechet;
            ans[i] = nechet;
            nechet += 2;
        }
        ans[n-1] = chetSum - nechetSum;
        cout << "YES" << endl;
        for (auto el : ans){
            cout << el << ' ';
        }
        cout << endl;
    }
    return 0;
}
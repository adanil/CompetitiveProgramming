#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    vector<ll>sumPow;
    unsigned long long curr = 1;
    unsigned long long s = 1;
    while(curr < 1000000000000000000){
        sumPow.push_back(s);
        curr *= 2;
        s = s*2 + 1;
    }
//    cout << sumPow.size() << endl;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        ll iter = 0;
        while (n > 0){
            if (n & 1 == 1)
                ans += sumPow[iter];
            iter++;
            n = n >> 1;
        }
        cout << ans << endl;

    }
    return 0;
}
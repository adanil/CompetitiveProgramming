#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {

    ll t;
    cin >> t;
    while(t--){
        ll n,x;
        cin >> n >> x;
        vector<ll>a(n);
        ll sum = 0;
        for (int i = 0;i < n;i++){
            cin >> a[i];
            sum += a[i];
        }
        ll q = n;

        sort(a.begin(),a.end());
        ll ans = 0;
        double avg = 0;
        avg = (double)sum /(double) n;
        while (avg < x && ans < q) {
            n -= 1;
            sum -= a[ans];
            ans++;
            avg = (double)sum /(double) n;
        }
        cout << n << endl;

    }


    return 0;
}
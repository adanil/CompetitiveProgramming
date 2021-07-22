#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll>s(n),d(n);
    for (int i = 0;i < n;i++)
        cin >> s[i] >> d[i];
    ll ans = s[0];
    for (int i = 1;i < n;i++){
        while (s[i] <= ans){
            s[i] += d[i];
        }
        ans = s[i];
    }
    cout << ans << endl;
    return 0;
}
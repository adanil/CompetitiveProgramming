#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m,w;
    cin >> n >> m >> w;
    vector<ll>a(n);
    for (auto &el :a)
        cin >> el;

    ll l = 0,r = *min(a.begin(),a.end()) + m + 5;

    vector<ll>st(n,0);
    ll ans = 0;

    while (l <= r){
        ll mid = (l + r)/2;
        ll mv = 0;
        ll curr = 0;
        fill(st.begin(),st.end(),0);
        for (int i = 0;i < n;i++){
            curr -= i - w >= 0 ? st[i - w] : 0;
            if (curr + a[i] < mid){
                st[i] = mid - a[i] - curr;
                curr += st[i];
                mv += st[i];
            }
        }
        if (mv <= m){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
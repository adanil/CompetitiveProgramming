#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll n,w,d;
    cin >> n >> w >> d;
    vector<ll>a(n);
    set<ll>st;
    for (int i = 0;i < n;i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    if (st.size() > w || n > w * d)
        cout << -1 << endl;
    else{
        sort(a.begin(),a.end());
        vector<vector<ll>>ans(w,vector<ll>());
        int curr = 0;
        ll prev = -1;
        for (auto el : a){
            if (prev != -1 && el != prev)
                curr++;
            if (ans[curr].size() >= d){
                cout << -1 << endl;
                return 0;
            }

            if (curr >= w){
                cout << -1 << endl;
                return 0;
            }
            else{
                ans[curr].push_back(el);
                prev = el;
            }
        }
        for (int i = 0;i < w;i++)
            if (!ans[i].empty())
                cout << ans[i][0] << ' ';
            else cout << 0 << ' ';
        cout << endl;
        for (int i = 0;i < w;i++)
            cout << ans[i].size() << ' ';
    }

    return 0;
}
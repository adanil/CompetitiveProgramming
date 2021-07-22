#include <iostream>
#include <vector>

using ll = long long;
using namespace std;


struct stree{
    ll n;
    vector<ll>s;
    stree(vector<ll> &a){
        n = a.size();
        ll dop = 1;
        while (dop < n){
            dop *= 2;
        }
        n = dop;
        a.resize(dop,0);
        s.resize(2*dop);
        for (int i = 0;i < n;i++){
            s[i + n - 1] = a[i];
        }
        bool fl = true;
        for (int i = n - 2;i >= 0;--i){
            s[i] = s[i*2 + 1] - s[i*2 + 2];
            if (!fl) {
                s[i] *= -1;
                fl = true;
            } else fl = false;
        }
    }

    void upd(int ind,int el){
        ind--;
        ll diff = el - s[ind + n - 1];
        s[ind + n - 1] = el;
        int i = ind + n - 1;
        while (i > 0){
            i = (i - 1)/2;
            s[i] += diff;
        }
    }

    ll sum(int l,int r){
        l--;r--;
        l += n-1;
        r += n-1;
        ll ans = 0;
        while (l <= r){
            if (l % 2 == 0) {
                ans += s[l];
                cout << "l: " <<  l << endl;
            }
            l /= 2;

            if (r % 2 == 1){
                ans += s[r];
                cout << r << endl;
            }
            r = r/2 - 1;
            cout << "ANS: " << ans << endl;
        }
        return ans;

    }


};




int main() {
    ll n,k;
    cin >> n;
    vector<ll> a(n,0);
    for (auto &el: a)
        cin >> el;
    stree tr(a);
    cin >> k;
    for (int i = 0;i < k;i++){
        int c;
        cin >> c;
        if (c == 0){
            ll ind,x;
            cin >> ind >> x;
            tr.upd(ind,x);
        }
        else{
            ll l,r;
            cin >> l >> r;
            cout << tr.sum(l,r) << endl;
        }
    }
    return 0;
}
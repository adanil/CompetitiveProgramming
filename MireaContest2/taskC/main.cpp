#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>



using namespace std;

using ll = unsigned long long;
using ld = long double;
ld maxvalue = 1000000000000000;

vector<ll> mults;

ll generator(vector<ll>&p,int n,ld mul,int ind);


int main() {
    ll l, r, n;
    ll ans = 0;
    cin >> l >> r >> n;
    l--;
    set<ll> sp;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        sp.insert(k);
    }
    vector<ll> p;
    for (auto it = sp.begin(); it != sp.end(); it++)
        p.push_back(*it);


    for (int i = 0; i < p.size(); i++) {
        ans += (r / p[i] - l / p[i]);
    }

    for (int i = 2;i <= p.size();i++) {
        mults.clear();
        generator(p, i, 1, 0);
        if (i % 2 == 0){
            for (ll j = 0;j < mults.size();j++){
                ans -= (r / mults[j] - l / mults[j]);
            }
        }
        else{
            for (ll j = 0;j < mults.size();j++){
                ans += (r / mults[j] - l / mults[j]);
            }
        }
    }



    cout << fixed<< setprecision(0)<< ans << endl;
    return 0;
}


ll generator(vector<ll>&p,int n,ld mul,int ind){
    if (n == 0) {
        mults.push_back(mul);
    }
    for (int i = ind;i < p.size();i++){
        if (mul * p[i] > maxvalue)
            return 0;
        generator(p,n-1,mul*p[i],i+1);

    }
}
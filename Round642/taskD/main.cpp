#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;



struct com{
    ll l;
    ll r;
    ll len;

    bool operator< (const com& a) const{
        return this->len != a.len ? this->len > a.len : this->l < a.l;
    }
};


void merge(vector<ll>&a,ll l,ll r,ll step,set<com> &cm){
    ll m = 0;
    if ((r - l)%2 != 0)
        m = (l + r)/2;
    else
        m = (l + r - 1)/2;

    a[m] = step;

    com cm1,cm2;
    cm1.l = m + 1;
    cm1.r = r;
    cm1.len = cm1.r - cm1.l;
    if (cm1.len != 0)
        cm.insert(cm1);

    cm2.l = l;
    cm2.r = m;
    cm2.len = cm2.r - cm2.l;
    if (cm2.len != 0 )
        cm.insert(cm2);

}

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>a(n);
        set<com> cm;
        ll step = 1;
        com command;
        command.l = 0;
        command.r = n;
        command.len = n;
        cm.insert(command);
        while (step - 1 != n){
            auto it = cm.begin();
            merge(a,it->l,it->r,step,cm);
            cm.erase(it);
            step++;
        }
        for (auto el : a)
            cout << el << ' ';
        cout << endl;
    }
    return 0;
}
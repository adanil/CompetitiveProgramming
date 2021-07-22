#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<tuple<ll,ll,ll>>sp(n);
    vector<tuple<ll,ll,ll>>nls;
    for (int i = 0;i < n;i++){
        ll d,p;
        cin >> d >> p;
        if (d == 0)

        get<0>(sp[i]) = d; get<1>(sp[i]) = p;
        get<2>(sp[i]) = i;
    }
    sort(sp.begin(),sp.end(),[](tuple<ll,ll,ll>a,tuple<ll,ll,ll>b){
        return get<0>(a) + get<1>(a)*get<0>(b) == get<0>(b) + get<1>(b)*get<0>(a) ? get<2>(a) < get<2>(b) : get<0>(a) + get<1>(a)*get<0>(b) < get<0>(b) + get<1>(b)*get<0>(a)  ;
    });

    for (int i = 0;i < n;i++){
        cout << get<2>(sp[i]) + 1 << ' ';
    }

    return 0;
}
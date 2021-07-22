#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> factors(ll n){
    vector<ll> result;
    for (ll i = 2;i*i <= n;i++){
        while(n % i == 0){
            result.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        result.push_back(n);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll,ll>>p(n);
    for (int i = 0;i < n;i++)
        cin >> p[i].first >> p[i].second;


    sort(p.begin(),p.end(),[](pair<ll,ll> a,pair<ll,ll>b){
        return min (a.first,a.second) < min(b.first,b.second);
    });

    vector<ll> fc = factors(p[0].first);
    auto fc2 = factors(p[0].second);
    fc.insert(fc.begin(),fc2.begin(),fc2.end());
    sort(fc.begin(),fc.end());
    for (int i = 0;i < n;i++){
        ll j = 0;
        while(j < fc.size()){
            if (fc[j] > p[i].first && fc[j] > p[i].second)
                fc.erase(fc.begin() + j,fc.end());
            else if (p[i].first % fc[j] !=0 && p[i].second % fc[j] != 0)
                fc.erase(fc.begin() + j);
            else
                j++;
        }
    }

    if (fc.size() == 0)
        cout << -1 << endl;
    else
        cout << fc[0] << endl;
    return 0;
}
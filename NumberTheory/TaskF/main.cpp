#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;
using ll = long long;

vector<ll> factors(ll n);

int main() {
    ll n;
    map<ll,ll>mp;
    cin >> n;
    ll ans = 1;
    for (ll i = 2;i <= n;i++){
        vector<ll> tmp = factors(i);
        for (ll j = 0;j < tmp.size();j++){
            if (mp.find(tmp[j]) != mp.end())
                mp[tmp[j]]++;
            else
                mp.insert(make_pair(tmp[j],1));
        }

    }
    for (auto it = mp.begin();it != mp.end();it++){
        //cout << it->first << ' ' << it->second << endl;
        ans  = (ans * (it->second +1))%1000000007;
    }
    cout << ans << endl;


    return 0;
}


vector<ll> factors(ll n){
    vector<ll> f;
    for (ll i = 2;i*i <= n;i++){
        while(n%i == 0){
            f.push_back(i);
            n /= i;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}
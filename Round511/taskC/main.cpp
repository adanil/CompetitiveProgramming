#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;


//vector<ll> factors(ll n){
//    vector<ll> result;
//    for (ll i = 2;i*i <= n;i++){
//        while(n % i == 0){
//            result.push_back(i);
//            n /= i;
//        }
//    }
//    if (n > 1)
//        result.push_back(n);
//    return result;
//}


ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n = 15000001;
    ll m;
    cin >> m;
    vector<ll>dig(m);
    vector<vector<int>>h(n + 1,vector<int>());
    for (int i = 0;i < m;i++){
        cin >> dig[i];
    }


    vector<vector<ll>>factors(m);

    map<ll,ll> freq;



    ll mgcd = gcd(dig[0],dig[1]);
    for (ll i = 2;i < m;i++){
        mgcd = gcd(mgcd,dig[i]);
    }

    ll i = 0;
    for (auto &el : dig){
        el /= mgcd;
        h[el].push_back(i + 1);
        i++;
    }

    vector<char> prime (n+1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2;i < n;i++){
        if (prime[i]) {
            for (ll j= i; j<=n; j+=i) {
                prime[j] = false;
                if (h[j].size() != 0) {
                    for (auto el : h[j]) {
                        freq[i]++;
                        factors[el - 1].push_back(i);
                    }
                }
            }
        }
    }


    ll maxDel = -1;
    ll maxFreq = -1;
    for (auto it = freq.begin();it != freq.end();it++){
        if (it->second > maxFreq){
            maxFreq = it->second;
            maxDel = it->first;
        }
    }
//    cout << maxFreq << ' ' << maxDel << endl;
    if (maxFreq == m || maxDel == -1)
        cout << -1 << "\n";
    else
        cout << m - maxFreq << "\n";
    return 0;
}
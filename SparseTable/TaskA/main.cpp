#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<ll>> buildSparseTable(const vector<ll> &a){
    size_t n = a.size();
    size_t maxk = log2(n);

    vector<vector<ll>>sparseTable(maxk + 1,vector<ll>(n));
    for (size_t i = 0;i < n;i++){
        sparseTable[0][i] = a[i];
    }
    for (size_t k = 1;k <= maxk;k++){
        for (size_t i = 0;i + pow(2,k) <= n;i++){
            sparseTable[k][i] = max(sparseTable[k - 1][i],sparseTable[k - 1][i + pow(2,k - 1)]);
        }
    }
    return move(sparseTable);
}

ll query(size_t l,size_t r,const vector<vector<ll>> &sparseTable){  // [l,r)
    size_t len = r - l;
    size_t k = log2(len);
    size_t d = pow(2,k);
    if (d == len)
        return sparseTable[k][l];
    else
        return max(sparseTable[k][l],sparseTable[k][r - d]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t,c;
    cin >> n >> t >> c;
    vector<ll>a(n);
    for (auto &el : a)
        cin >> el;

    vector<vector<ll>> st = buildSparseTable(a);
    ll ans = 0;
    for (size_t i = 0;i + c <= n;i++){
        if (query(i,i + c,st) <= t)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
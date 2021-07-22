#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

static vector<vector<ll>> stmx(18,vector<ll>(200001));
static vector<vector<ll>> stmn(18,vector<ll>(200001));

void buildSparseTable(const vector<ll> &a,const function<ll(ll,ll)> &comp){
    size_t n = a.size();
    size_t maxk = 18;
//    vector<vector<ll>>sparseTable(maxk + 1,vector<ll>(n));
    for (size_t i = 0;i < n;i++){
        stmx[0][i] = a[i];
    }
    for (size_t k = 1;k <= maxk;k++){
        for (size_t i = 0;i + (1u << k) < n;i++){
            stmx[k][i] = comp(stmx[k - 1][i],stmx[k - 1][i + (1u << (k - 1))]);
        }
    }
//    return st;
}

void buildSparseTable2(const vector<ll> &a,const function<ll(ll,ll)> &comp){
    size_t n = a.size();
    size_t maxk = 18;
//    vector<vector<ll>>sparseTable(maxk + 1,vector<ll>(n));
    for (size_t i = 0;i < n;i++){
        stmn[0][i] = a[i];
    }
    for (size_t k = 1;k <= maxk;k++){
        for (size_t i = 0;i + (1u << k) < n;i++){
            stmn[k][i] = comp(stmn[k - 1][i],stmn[k - 1][i + (1u << (k - 1))]);
        }
    }
//    return st;
}

ll query(size_t l,size_t r,const vector<vector<ll>> &sparseTable,const function<ll(ll,ll)> &comp){  // [l,r)
    size_t len = r - l;
    size_t k = log2(len);
    size_t d = (1 << k);
    if (d == len)
        return sparseTable[k][l];
    else
        return comp(sparseTable[k][l],sparseTable[k][r - d]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll>a(n),b(n);
    for (auto &el : a)
        cin >> el;
    for (auto &el : b)
        cin >> el;

    function<ll(ll,ll)> mx = [&](ll a,ll b){return max(a,b);};
    function<ll(ll,ll)> mn = [&](ll a,ll b){return min(a,b);};

    buildSparseTable(a,mx);
    buildSparseTable2(b,mn);

    ll ans = 0;
    for (int l = 0;l < n;l++){
        int q = n;
        bool fl = false;
        int tmp = 0;
        int r = (q + l)/2;
        while (r >= l && r < q){
            if (query(l,r + 1,stmx,mx) - query(l,r + 1,stmn,mn) < 0)
                r = (q + r + 1)/2;
            else {
                if (!fl) {
                    tmp = r;
                    fl = true;
                }
                q = r;
                r = (l + r) / 2;
            }
        }

        int leftBound = r;

        q = n;

        r = tmp;
        while (r >= l && r < q){
            if (query(l,r + 1,stmx,mx) - query(l,r + 1,stmn,mn) <= 0)
                r = (q + r + 1)/2;
            else {
                q = r;
                r = (l + r) / 2;
            }
        }

        if (r - leftBound > 0)
            ans += r - leftBound;
    }

    cout << ans << endl;
    return 0;
}
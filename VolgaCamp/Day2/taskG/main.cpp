#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 10000000000000000;

struct fenwick {
    vector<ll> tree;

    void init(size_t sz) {
        tree.resize(sz + 1, 0);
    }

    ll sum(int k) {
        ll s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int pos, ll val) {
        while (pos <= tree.size() -1) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin >> n >> k;
    fenwick fw;
    fw.init(n);
    vector<ll>income(n);
    for (int i = 0;i < n;i++) {
        cin >> income[i];
        fw.add(i + 1,income[i]);
    }
    ll ans = 0;
    ll minEl = *min_element(income.begin(),income.end());
    ll minSum = INF;
    ll ind1 = 0,ind2 = 0;

    for (int i = 0;i < n - k  + 1;i++){
        ll s;
        if ((s = fw.sum(i+1,i+k)) >= 0){
            ans += s + 1;
            ind1 = i;
            ind2 = i + k;

            for (int j = ind2 - 1;j >= ind1;j--){
                if (s < 0)
                    break;
                if (income[j] - (s + 1) >= minEl){
                    fw.add(j + 1,-(s + 1));
                    income[j] -= (s + 1);
                    s = -1;
                }
                else{
                    s -= abs(minEl - income[j]);
                    fw.add(j + 1,-abs(minEl - income[j]));
                    income[j] = minEl;
                }
            }




        }
    }
//    if (minSum >= 0){
//        for (int i = ind1;i < ind2;i++){
//            if (minSum < 0)
//                break;
//            if (income[i] - (minSum + 1) >= minEl){
//                income[i] -= (minSum + 1);
//                minSum = -1;
//            }
//            else{
//                minSum -= abs(minEl - income[i]);
//                income[i] = minEl;
//            }
//        }
//    }
    cout << ans << endl;
    for (int i = 0;i < n;i++)
        cout << income[i] << ' ';
    cout << endl;

    return 0;
}
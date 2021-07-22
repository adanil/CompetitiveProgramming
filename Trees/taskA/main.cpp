#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    fenwick fw;
    fw.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fw.add(i, a[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "sum") {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        } else {
            int pos;
            ll val;
            cin >> pos >> val;
            fw.add(pos, val - a[pos]);
            a[pos] = val;
        }
    }
    return 0;
}
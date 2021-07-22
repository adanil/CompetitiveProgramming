#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    ordered_set st;
    ll n,p;
    cin >> n >> p;
    ll count = n;
    for (int i = 1;i <= n;i++){
        st.insert(i);
    }
    ll last = 0;
    vector<ll> ans;
    while (count > 1){
        for (auto it: st)
            cout << it << ' ';
        cout << endl;
        if ((last + p) % n == 0){
            st.erase(st.find_by_order(n + last - 1));
            last = n - 1;
        }
        else{
            st.erase(st.find_by_order(p % (n + last) + last - 1));
            last = p % n - 1;
        }
        n--;
        count--;
    }
    cout << *st.begin() << endl;
    return 0;
}

// 1 2 3
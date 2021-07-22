#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

struct fenwick{
    vector<ll> tree;

    void add(int ind,int delta){
        for (;ind < tree.size();ind = (ind | (ind + 1)))
            tree[ind] += delta;
    }

    fenwick(size_t sz){
        tree.resize(sz);
    }
    fenwick(const vector<ll> &v){
        tree.resize(v.size(),0);
        for (int i = 0;i < v.size();i++)
            add(i,v[i]);
    }

    ll sum (int r){
        ll res = 0;
        for (;r >= 0;r = (r &(r + 1)) - 1)
            res += tree[r];
        return res;
    }

    ll sum (int l,int r){
        return sum(r) - sum(l - 1);
    }
};

vector<ll> mems;

int compress(ll val){
    return lower_bound(mems.begin(),mems.end(),val) - mems.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<char,ll>>data;
    int n;
    cin >> n;
    mems.resize(n);
    int pnt = 0;
    for (int i = 0;i < n;i++){
        char c;
        ll el;
        cin >> c >> el;
        data.emplace_back(c,el);
        if (c == '+') {
            mems[pnt] = el;
            pnt++;
        }
    }
    mems.resize(pnt);
    sort(mems.begin(),mems.end());
    mems.resize(unique(mems.begin(),mems.end()) - mems.begin());
    fenwick fw(mems.size());
    for (int i = 0;i < n;i++){
        char c = data[i].first;
        ll el = data[i].second;
        if (c == '+'){
            fw.add(compress(el),1);
        }
        else if (c == '-'){
            fw.add(compress(el),-1);
        }
        else {
            int ind = compress(el);
            cout << fw.sum(ind - 1) << '\n';
        }
    }
    cout.flush();
    return 0;
}
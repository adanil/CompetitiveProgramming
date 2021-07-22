#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct fenwick{
    vector<ll>tree;

    void init(size_t sz){
        tree.resize(sz + 1,0);
    }

    void add(int pos,int val){
        while (pos < tree.size()){
            tree[pos] += val;
            pos += pos & -pos;
        }
    }

    ll sum(int k){
        ll s = 0;
        while (k >= 1){
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }
    ll sum (int l,int r){
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    fenwick fw;
    fw.init(n);
    for (int i = 0;i < m;i++){
        string s;
        cin >> s;
        if (s == "add"){
            int pos,val;
            cin >> pos >> val;
            fw.add(pos,val);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << fw.sum(l,r) << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct fenwick {
    int sz = 1000000;
    vector<int>tree;

    fenwick(){
        tree.resize(sz,0);
    }

    void add(int k,int val){
        for (int i = k;i < sz;i = (i |(i + 1)))
            tree[i] += val;
    }

    ll sum (int r){
        ll res = 0;
        for (;r >= 0;r = (r &(r + 1)) - 1)
            res += tree[r];
        return res;
    }

    int find(int target){
        int r = sz;
        int l = 0;
        int m = -1;
        while(l < r){
            m = (r + l)/2;
            int s = sum(m);
            if (s >= target){
                r = m;
            } else
                l = m + 1;
        }
        return l;

    }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    fenwick fw;
    vector<int> inp;
    for (int i = 0;i < n;i++){
        int el;
        cin >> el;
        el--;
        inp.push_back(el);
        fw.add(el,1);
    }
    for (int i = 0;i < q;i++){
        int el;
        cin >> el;
        if (el >= 1){
            fw.add(el - 1,1);
            inp.push_back(el - 1);
        }
        else{
            fw.add(fw.find(-el),-1);
        }
    }

    bool fl = false;

    sort(inp.begin(),inp.end());
    for (int i = 0;i < inp.size();i++){
        if (fw.tree[inp[i]] != 0){
            cout << inp[i] + 1 << endl;
            fl = true;
            break;
        }
    }
    if (!fl){
        cout << 0 << endl;
    }
    return 0;
}
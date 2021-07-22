#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


struct segTree{
    vector<ll>tree;
    ll n = 1;
    ll neutral = 0;
    vector<bool>actual;

    void init(const vector<ll> &arr){
        while(n < arr.size())
            n <<=1;
        tree.resize(2*n - 1,neutral);
        for (int i = 0;i < arr.size();i++){
            tree[i + n - 1] = (1ll << (arr[i] - 1));
        }
        for (int i = n - 2;i >= 0;i--){
            tree[i] = (tree[i*2 + 1] | tree[i*2 + 2]);
        }
        actual.resize(n,true);
//        cout << "n = " << n << endl;
    }


    void setColor(int color,int l,int r,int lx,int rx,int vert, bool need_push = false, ll pushColor = 0){
        if (need_push) {
            tree[vert] = pushColor;
            actual[vert] = false;
        }
        if (l >= rx || r <= lx)
            return;
        else if(lx >= l && rx <= r){
            tree[vert] = (1ll<<color);
            actual[vert] = false;
            while (vert != 0){
                vert /= 2;
                tree[vert] |= (1ll << color);
            }
            return;
        }

        if (!actual[vert]){
            need_push = true;
            actual[vert] = true;
            pushColor = tree[vert];
        }

        int m = (lx + rx)/2;
        setColor(color,l,r,lx,m,2*vert + 1,need_push,pushColor);
        setColor(color,l,r,m,rx,2*vert + 2,need_push,pushColor);
    }

    void setColor(int color,int l,int r){
        color--;
        setColor(color,l,r,0,n,0);
    }


    ll getDiffColors(int l,int r,int lx,int rx,int vert,bool need_push = false,ll pushColor = 0){
        if (need_push) {
            tree[vert] = pushColor;
            actual[vert] = false;
        }
        if (l >= rx || r <= lx)
            return 0;
        else if(lx >= l && rx <= r){
            return tree[vert];
        }

        if (!actual[vert]){
            need_push = true;
            actual[vert] = true;
            pushColor = tree[vert];
        }

        int m = (lx + rx)/2;
        ll a = getDiffColors(l,r,lx,m,2*vert + 1,need_push,pushColor);
        ll b = getDiffColors(l,r,m,rx,2*vert + 2,need_push,pushColor);
        return (a | b);
    }


    ll getDiffColors(int l,int r){
        return getDiffColors(l,r,0,n,0);
    }



};

int t = 0;
vector<vector<ll>>g;
vector<char>used;
vector<int>tin;
vector<int>tout;

vector<ll>euler;

void dfs(int v){
    euler.push_back(v);
    used[v] = 1;
    tin[v] = t++;
    for (auto to : g[v]) {
        if (!used[to])
            dfs(to);
    }
    tout[v] = t;
}



int main() {

//    vector<ll> arr = {1,1,1,2,2,3};
//    segTree sgt;
//    sgt.init(arr);
//
//    cout << __builtin_popcountll(sgt.getDiffColors(0,6)) << endl;





    ll n,m;
    cin >> n >> m;
    vector<ll>color(n);
    for (ll i = 0;i < n;i++){
        cin >> color[i];
    }
    g.resize(n);
    used.resize(n,false);
    tin.resize(n);
    tout.resize(n);
    for (int i = 0;i < n - 1;i++){
        ll from,to;
        cin >> from >> to;
        from--;to--;
        g[from].push_back(to);
    }
    dfs(0);

    segTree sgt;
    vector<ll> arr(euler.size());
    for (int i = 0;i < euler.size();i++){
        arr[i] = color[euler[i]];
    }
    sgt.init(arr);

    for (int i = 0;i < m;i++){
        int com,v,cl;
        cin >> com;
        if (com == 1){
            cin >> v >> cl;
            v--;
//            cout <<"verts: " << tin[v] << ' ' << tout[v] << endl;
            sgt.setColor(cl,tin[v],tout[v]);
        }
        else{
            cin >> v;
            v--;
            cout << __builtin_popcountll(sgt.getDiffColors(tin[v],tout[v])) << endl;
        }
    }

    return 0;
}
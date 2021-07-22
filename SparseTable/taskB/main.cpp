#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 2000000000000000;


ll query(int l,int r,const vector<vector<int>> &st){
    int len = r-l;
    int k = log2(len);
    if ((1 << k) == len){
        return st[k][l];
    }
    else{
        return min(st[k][l],st[k][r - (1u << k)]);
    }
}

int main() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    ll g,x,y,z;
    cin >> g >> x >> y >> z;
    vector<vector<int>>data(n,vector<int>(m));

    vector<int>tmp(n*m);
    tmp[0] = g;
    for (int i = 1;i < n*m;i++)
        tmp[i] = (tmp[i - 1]*x + y)%z;

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++)
            data[i][j] = tmp[i * m + j];
    }

    tmp.clear();

    int logn = log2(n);
    int logm = log2(m);
    int loga =log2(a);
    int logb = log2(b);


    vector<vector<int>>st(logn + 1,vector<int>(n));
    vector<vector<int>>prev(n,vector<int>(m)),curr;
    for (int i = 0;i < m;i++){
        for (int j = 0;j < n;j++){
            st[0][j] = data[j][i];
        }
        for (int k = 1;k <= logn;k++){
            for (int j = 0;j + (1 << k) <= n;j++){
                st[k][j] = min(st[k - 1][j],st[k - 1][j + (1 << (k-1))]);
            }
        }
        for (int j = 0;j < n;j++){
            prev[j][i] = query(j,j + a,st);
        }
    }
    curr = prev;


//    for (int i = 0;i + a <= n;i++){
//        for (int j = 0;j < m;j++){
//            prev[i][j] = query(i,i + a,st,j);
//        }
//        curr = prev;
//    }
    for (int k = 1;k <= logb;k++){
        for (int i = 0;i + a <= n;i++){
            for (int j = 0;j + (1 << k) <= m;j++){
                curr[i][j] = min(prev[i][j],prev[i][j + (1 << (k - 1))]);
            }
        }
        prev = curr;
    }
    ll ans = 0;
    for (int i = 0;i + a <= n;i++){
        for (int j = 0;j + b <= m;j++){
            if ((1 << logb) == b)
                ans += curr[i][j];
            else{
                ans += min(curr[i][j],curr[i][j + b - (1 << logb)]);
            }
        }
    }
    cout << ans << endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;


ll query(int x1,int y1,int x2,int y2,const vector<vector<int>> &st,int kx,int ky){
//    int kx = log2(x2 - x1);
//    int ky = log2(y2 - y1);
    ll ans1 = st[x1][y1];
    ll ans2 = st[x2 - (1u << kx)][y2 - (1u << ky)];
    ll ans3 = st[x2 - (1u << kx)][y1];
    ll ans4 = st[x1][y2 - (1u << ky)];
    return min(min(ans1,ans2),min(ans3,ans4));
}

int main() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    ll g,x,y,z;
    cin >> g >> x >> y >> z;
    vector<vector<ll>>data(n,vector<ll>(m));

    vector<ll>tmp(n*m);
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
    int loga = log2(a);
    int logb = log2(b);

    vector<vector<int>> st(n,vector<int>(m));

    vector<vector<int>> curr(n,vector<int>(m)),prev(n,vector<int>(m));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++)
            curr[i][j] = data[i][j];
    }

//    for (int i = 0;i < n;i++){
//        for (int k = 1;k <= logm;k++){
//            for (int j = 0;j + (1 << k) <= m;j++){
//                st[i][j][0][k] = min(st[i][j][0][k - 1],st[i][j + (1u <<(k - 1))][0][k-1]);
//            }
//        }
//    }
//
//    for (int j = 0;j < m;j++){
//        for (int k = 1;k <= logn;k++){
//            for (int i = 0;i + (1 << k) <= n;i++){
//                st[i][j][k][0] = min(st[i][j][k - 1][0],st[i + (1u <<(k - 1))][j][k-1][0]);
//            }
//        }
//    }

    prev = curr;

    for (int lgn = 1;lgn <= loga;lgn++){
        for (int i = 0;i + (1u << lgn) <= n;i++){
            for (int lgm = 1;lgm <= logb;lgm++){
                for (int j = 0;j + (1u << lgm) <= m;j++){
                    curr[i][j] = min(prev[i][j],prev[i + (1u << (lgn - 1))][j]);
//                    st[i][j][lgn][lgm] = min(st[i][j][lgn - 1][lgm],st[i + (1u << (lgn - 1))][j][lgn-1][lgm]);
                }
                prev = curr;
            }
        }
    }


    ll ans = 0;
    for (int i = 0;i <= n - a;i++){
        for (int j = 0;j <= m - b;j++){
            ans += query(i,j,i + a,j + b,curr,loga,logb);
        }
    }
    cout << ans << endl;
    return 0;
}
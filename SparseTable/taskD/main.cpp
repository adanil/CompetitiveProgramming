#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;

ll query(int l,int r, const vector<vector<vector<ll>>>&st,int m){
    int len = r-l;
    int k = 0;
    while((1u << k) < len){
        k++;
    }
    if ((1 << k) == len){
        return st[m][k][l];
    }
    else{
        k--;
        return max(st[m][k][l],st[m][k][r - (1u << k)]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>>data(m,vector<ll>(n));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++)
            cin >> data[j][i];
    }

    vector<vector<vector<ll>>>st(m,vector<vector<ll>>(30,vector<ll>(n)));
    for (int i = 0;i < m;i++){
        for (int j = 0;j < n;j++)
            st[i][0][j] = data[i][j];
        for (int q = 1;q < 30;q++){
            for (int t = 0;t + (1u << q) <= n;t++){
                st[i][q][t] = max(st[i][q - 1][t],st[i][q - 1][t + (1u << (q - 1))]);
            }
        }
    }

    vector<ll>ans(m);
    vector<ll>result(m);
    int q = n;
    int l = 0,r;
    r = (l + q)/2;
    while (r >= l && r < q){
        bool fl = false;
        int len = r;
        if (len == 0)
            len = 1;
        ll sum = 0;
        for (int left = 0;left + len <= n;left++){
            sum = 0;
            for (int i = 0;i < m;i++){
                ll s = query(left,left+len,st,i);
                sum += s;
                if (sum > k)
                    break;
                ans[i] = s;
            }
            if (sum <= k){
                fl = true;
                break;
            }
        }
        if (fl){
            result = ans;
            l = r;
            r = (r + q + 1)/2;
        }
        else{
            q = r;
            r = (l + r)/2;
        }
    }

    for (auto &el : result)
        cout << el << ' ';


    return 0;
}
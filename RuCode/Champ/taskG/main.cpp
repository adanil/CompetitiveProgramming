#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>>a(n,vector<ll>(m));
    vector<vector<ll>>dp(n,vector<ll>(m));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }


    return 0;
}
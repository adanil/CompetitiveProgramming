#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll,ll>>a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(),a.end(),[](pair<ll,ll>a,pair<ll,ll> b){return a.second + b.first < a.first + b.second;});

    ll ans = a[0].first;
    ll locans = ans;
    for (int i = 0;i < n - 1;i++){
        if (locans - a[i].second < a[i+1].first){
            ans += a[i+1].first - (locans - a[i].second);
            locans = a[i+1].first;
        }
        else
            locans -= a[i].second;
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;
    ll a = 0;
    vector<pair<ll,ll>>p(n);
    for (int i = 0;i < n;i++){
        cin >> p[i].first >> p[i].second;
        if (p[i].first + p[i].second > a){
            a = p[i].first + p[i].second;
        }
    }
    cout << a << endl;
    return 0;
}
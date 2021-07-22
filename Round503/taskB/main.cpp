#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll>p(n);
    for (int i = 0; i < n;i++)
        cin >> p[i];
    for (int i = 0;i < n;i++){
        set<ll>sc;
        ll curr = i;
        sc.insert(curr + 1);
        while(sc.count(p[curr]) == 0){
            curr = p[curr] - 1;
            sc.insert(curr + 1);
        }
        cout << p[curr] << ' ';
    }
    return 0;
}
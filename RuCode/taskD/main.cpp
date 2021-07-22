#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {

    ll bridge = 60;
    ll vag = 15;

    ll ans = 0;

    ll n,m;
    cin >> n >> m;
    ll lok;
    cin >> lok;

    vector<ll> w(m-1,0);
    for (int i = 0;i < m-1;i++)
        cin >> w[i];

    n -= lok;

    for (int i = 0;i < m-1;i++){
        if (i == 3){
            n += lok;
        }
        else if (i > 3){
            n += w[i - 4];
        }
        n -= w[i];
        if (n >= 0)
            ans++;
        else
            break;
    }

    cout << ans << endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
using ll = long long;

vector<ll>x,y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int t = 1;
    while (n != 0){
        x.clear();
        y.clear();
        ll ans = 0;
        for (int i = 0;i < n;i++){
            ll xtmp,ytmp;
            cin >> xtmp >> ytmp;
            x.push_back(xtmp);
            y.push_back(ytmp);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ll xVal,yVal;
        if (n % 2 != 0){
            xVal = x[n/2];
            yVal = y[n/2];
        }
        else{
            xVal = x[n/2 - 1];
            yVal = y[n/2 - 1];
        }

        for (ll i = 0;i < x.size();i++){
            ans += abs(x[i] - xVal);
            ans += abs(y[i] - yVal);

        }
        cout << "Case " << t << ": (" <<xVal << ',' << yVal <<") " << ans << endl;
        cin >> n;
        t++;
    }
    return 0;
}
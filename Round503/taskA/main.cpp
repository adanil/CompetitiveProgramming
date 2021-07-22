#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0;i < k;i++){
        ll ta,fa,tb,fb;
        cin >> ta >> fa >> tb >> fb;
        ll ans = abs(ta - tb);
        if (ta == tb){
            ans += abs(fa - fb);
            cout << ans << endl;
            continue;
        }
            if (fa >= a && fa <= b)
                ans += abs(fb - fa);
            else {
                ll curr = 0;
                if (abs(fa - a) < abs(fa - b)) {
                    curr = a;
                    ans += abs(fa - a);
                } else {
                    curr = b;
                    ans += abs(fa - b);
                }

                ans += abs(fb - curr);
            }
        cout << ans << endl;
    }


    return 0;
}
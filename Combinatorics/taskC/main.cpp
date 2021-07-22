#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll r,g,b;
    cin >> r >> g >> b;
    ll ans = 0;
    ll cnt = 0;
//    cout << g % 3 << endl;
    ll mn = max((r%3),(g%3));
    mn = max(mn,b%3);
    do{
        if (r == 0 || b == 0 || g == 0)
            break;
        cnt = 0;
        if (r % 3 != 0)
            cnt++;
        if (g % 3 != 0)
            cnt++;
        if (b % 3 != 0)
            cnt++;
        if (cnt > 1){
                ans++;
                r--;
                g--;
                b--;
                mn--;
        }
    }while(cnt > 1 && mn > 0);


    ans += r/3;
    ans += g/3;
    ans += b/3;

    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int q;
    cin >> q;
    for (int i = 0;i < q;i++){
        ll n;
        cin >> n;
        vector<ll> t(n);
        for (ll j = 0;j < n;j++){
            cin >> t[j];
        }

        bool has = false;
        ll indHas = 0;

        ll colors = 1;
        ll prevType =t[0];
        ll prevColor = 1;
        vector<ll> ans(n);
        for (ll j = 0;j < n;j++){
            if (j > 0){
                if (t[j] == t[j -1]) {
                    has = true;
                    indHas = j;
                }
            }
            if (t[j] == prevType){
                ans[j] = prevColor;
            }
            else {
                if (colors == 1){
                    colors++;
                    ans[j] = colors;
                    prevColor = colors;
                }
                else{
                    if (ans[j - 1] == 1){
                        ans[j] = 2;
                        prevColor = 2;
                    }
                    else{
                        ans[j] = 1;
                        prevColor = 1;
                    }
                }
            }
            prevType = t[j];
        }

        if (t[0] != t[n-1] && ans[0] == ans[n-1]){
            if (!has) {
                colors++;
                ans[n - 1] = colors;
            }
            else{
                ll clr = 0;
                if (ans[indHas - 1] == 1) {
                    ans[indHas] = 2;
                    clr = 2;
                }
                else {
                    ans[indHas] = 1;
                    clr = 1;
                }
                for (ll j = indHas + 1;j < n;j++){
                    prevType =t[j - 1];
                    if (t[j] == prevType){
                        ans[j] = prevColor;
                    }
                    else {
                        if (colors == 1){
                            colors++;
                            ans[j] = colors;
                            prevColor = colors;
                        }
                        else{
                            if (ans[j - 1] == 1){
                                ans[j] = 2;
                                prevColor = 2;
                            }
                            else{
                                ans[j] = 1;
                                prevColor = 1;
                            }
                        }
                    }
                }
            }
        }

        cout << colors << endl;
        for (ll j = 0;j < n-1;j++)
            cout << ans[j] << ' ';
        cout  << ans[n-1] << endl;


    }
    int b;
    return 0;
}
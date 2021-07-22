#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for (auto &el : a)
        cin >> el;


    int q = n;
    int l = 0,r;
    r = (l + q)/2;
    pair<int,int>result;
    vector<bool>check(1000001,false);
    while (r >= l && r < q){
        bool fl = false;
        int len = r;
        len++;

        int tmpl,tmpr;
        for (int i = 0;i + len <= n;i++){

           fill(check.begin(),check.end(),false);
            int curr = 0;
            for (int j = 0;j < len;j++){
                if (check[a[i+j]])
                    continue;
                else {
                    check[a[i + j]] = true;
                    curr++;
                }
            }
            if (curr <= k) {
                fl = true;
                tmpl = i + 1;
                tmpr = tmpl + len - 1;
            }
        }

        if (fl){
            result = {tmpl,tmpr};
            l = r;
            r = (r + q + 1)/2;
        }
        else{
            q = r;
            r = (l + r)/2;
        }
    }
    cout << result.first << ' ' << result.second << '\n';
    return 0;
}
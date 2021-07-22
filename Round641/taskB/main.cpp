#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct model{
    ll value;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<model> a(n);
        for (int i = 0;i < n;i++){
            model md;
            cin >> md.value;
            md.id = i + 1;
            a[i] = md;
        }

        vector<ll>ans(n + 1,1);
       for (int i = n-1;i >= 0;i--){
           ll id = a[i].id;
           ll start = id;
           ll st = ans[start];
           while(id + start <= n){
               id += start;
               if (a[id - 1].value > a[start - 1].value )
                   ans[start] = max(st + ans[id],ans[start]);
           }
       }
       cout << *max_element(ans.begin() + 1,ans.end()) << endl;
    }
    return 0;
}
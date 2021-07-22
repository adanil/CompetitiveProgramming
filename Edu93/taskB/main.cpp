#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int>a;
        int cnt = 0;
        for (int i = 0;i < s.size();i++){
            if (cnt != 0 && s[i] == '0'){
                a.push_back(cnt);
                cnt = 0;
            }
            else if (s[i] == '1')
                cnt++;
        }
        if (cnt != 0)
            a.push_back(cnt);
        sort(a.begin(),a.end(),[](int a,int b){
            return a > b;
        });
        ll ans = 0;
        for (int i = 0;i < a.size();i += 2){
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
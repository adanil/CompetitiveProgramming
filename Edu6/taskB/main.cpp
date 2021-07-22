#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
using ll = long long;

int main() {
    unordered_map<char,int>mp;
    mp['0'] = 6;
    mp['1'] = 2;
    mp['2'] = 5;
    mp['3'] = 5;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 3;
    mp['8'] = 7;
    mp['9'] = 6;
    int a,b;
    cin >> a >> b;
    ll ans = 0;
    for (int i = a;i <= b;i++){
        string s = to_string(i);
        for (auto c : s)
            ans += mp[c];
    }
    cout << ans << endl;

    return 0;
}
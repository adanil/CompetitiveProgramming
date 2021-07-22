#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {

    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll bal = 0;
    vector<ll>b(n);
    ll curr = 0;
    ll open = 0;
    ll close = 0;
    int i = 0;
    string ans;
    while (curr != k){
        if (s[i] == '(' && open < k/2){
            bal++;
            ans += '(';
            curr++;
            open++;
        }
        else if (s[i] == ')' && bal > 0 && close < k/2){
            bal--;
            ans += ')';
            curr++;
            close++;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
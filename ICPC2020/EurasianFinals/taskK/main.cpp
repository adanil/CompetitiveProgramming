#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
using ll = long long;

bool correct(string &s){
    int one = 1;
    int zero = 1;
    int two = 2;
    for (auto &c : s){
        if (c == '2' && two > 0)
            two--;
        else if(c == '1' && one > 0){
            one--;
        }
        else if (c == '0' && zero > 0)
            zero--;
    }
    if (!one && !zero && !two)
        return true;
    else
        return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int ans = -1;
    ll minCost = 100000000000;
    cin >> n;
    for (int i = 0;i < n;i++){
        ll cost;
        string s;
        cin >> cost >> s;
        if (correct(s) && cost < minCost) {
            minCost = cost;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
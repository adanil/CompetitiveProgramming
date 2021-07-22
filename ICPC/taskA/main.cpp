#include <iostream>
#include <string>
#include <vector>
using ll = long long;

using namespace std;


int main() {
    bool has = false;
    string s;
    string sprev;
    ll ans = 0;
    while (getline(cin,s)){
//        cout << s << endl;
        if (has){
            if (sprev[0] > s[0])
                ans++;
        }
        sprev = s;
        has = true;
    }
    cout << ans << endl;

    return 0;
}
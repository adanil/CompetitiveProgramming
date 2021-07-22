#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

bool isUpper(char c) {
    if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string cp = s;
    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (isUpper(s[i]) && isUpper(s[i + 1])) {
            s[i + 1] += 32;
            ans++;
        } else if (!isUpper(s[i]) && !isUpper(s[i + 1])) {
            s[i + 1] -= 32;
            ans++;
        }
    }
    if (s.size() > 1){
        if (isUpper(cp[0]) && isUpper(cp[1])) {
            cp[0] += 32;
            ans2++;
        } else if (!isUpper(cp[0]) && !isUpper(cp[1])) {
            cp[1] -= 32;
            ans2++;
        }

        for (int i = 0; i < cp.size() - 1; i++) {
            if (isUpper(cp[i]) && isUpper(cp[i + 1])) {
                cp[i + 1] += 32;
                ans2++;
            } else if (!isUpper(cp[i]) && !isUpper(cp[i + 1])) {
                cp[i + 1] -= 32;
                ans2++;
            }
        }
        cout << min(ans, ans2) << endl;
    }
    else
        cout << ans << endl;


    return 0;
}
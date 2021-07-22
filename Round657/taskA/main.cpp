#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string temp = "abacaba";
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n;
        cin >> s;
        string ans = s;
        n = s.size();

        int ps = ans.find(temp,0);
        if (ps != string::npos && ans.find(temp,ps + 1) == string::npos){
            for (int i = 0;i < n;i++) {
                if (ans[i] == '?')
                    ans[i] = 'q';
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            bool fl = true;
            for (int i = 0; i < n; i++) {
                fl = true;
                int q = 0;
                for (int j = i; j < i + temp.size(); j++) {
                    if (s[j] == temp[q] || s[j] == '?') {
                        q++;
                    } else {
                        fl = false;
                        break;
                    }
                }
                if (fl) {
                    ans = s;
                    q = 0;
                    for (int b = 0; b < n; b++) {
                        if (ans[b] == '?')
                            ans[b] = 'q';
                    }
                    for (int j = i; j < i + temp.size(); j++) {
                        ans[j] = temp[q];
                        q++;
                    }
                    int ps = ans.find(temp, 0);
                    if (ans.find(temp, ps + 1) != string::npos) {
                        fl = false;
                    }
                    if (fl) {
                        cout << "YES" << endl;
                        cout << ans << endl;
                        break;
                    }
                }
            }
            if (!fl)
                cout << "NO" << endl;
        }

    }
    return 0;
}
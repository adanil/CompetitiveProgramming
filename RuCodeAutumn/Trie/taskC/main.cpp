#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;
    vector<ll>pows(s.size() + 1);
    ll p = 31;
    pows[0] = 1;
    for (int i = 1;i < s.size() + 1;i++)
        pows[i] = pows[i - 1] * p;


    vector<ll>pr(s.size());
    for (int i = 0;i < s.size();i++){
        if (i == 0)
            pr[i] = s[i] - 'a' + 1;
        else
            pr[i] = pr[i - 1] + (s[i] - 'a' + 1)*pows[i];
    }
    ll ans = 0;
    for (int len = 1;len <= s.size();len++){
        set<ll>st;
        for (int i = 0;i <= s.size() - len;i++){
            ll curr_h = pr[i + len - 1];
            if (i > 0)
                curr_h -= pr[i - 1];
            curr_h *= pows[s.size() - i - len];
            st.insert(curr_h);
        }
        ans += st.size();
    }
    cout << ans << endl;
    return 0;
}
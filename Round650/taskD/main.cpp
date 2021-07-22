#include <iostream>
#include <vector>
#include <string>
#include <set>

using ll = long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    while(q--){

        set<ll>usedInd;
        string s;
        cin >> s;
        set<char>st;
        for (int i = 0;i < s.size();i++)
            st.insert(s[i]);
        ll m;
        cin >> m;
        vector<pair<ll,ll>>b;
        for (int i = 0;i < m;i++) {
            ll el;
            cin >> el;
            b.emplace_back(el,i);
        }
        vector<char>used(m);
        sort(b.begin(),b.end());
        vector<char>ans(m);
        ll curr = s.size() - 1;
        auto it = --st.end();
        for (int i = 0;i < m;i++){
            if (b[i].first == 0) {
                ans[b[i].second] = *(it);
                used[i] = *(it);
                if (st.size() > 1)
                    it--;
                st.erase(--st.end());
                usedInd.insert(b[i].second);
            }
            else{
                char chr = *(it);
                set<ll>tmp;
                for (int j = 0;j < i;j++){
                    if (b[j].first < b[i].first) {
                        b[i].first -= abs(b[i].second - b[j].second);
                        tmp.insert(b[j].second);
                        while(chr >= used[j]){
                            if (st.size() > 1)
                                it--;
                            chr = *it;
                        }
                    }
                }
                for (auto el : usedInd){
                    if (tmp.find(el) == tmp.end())
                        ans[el] = chr;
                }
                ans[b[i].second] = chr;
                usedInd.insert(b[i].second);
                used[i] = chr;
                auto copy = it;
                if (st.size() > 1)
                    it--;
                st.erase(copy);

            }
        }
        for (int i = 0;i < ans.size();i++)
            cout << ans[i];
        cout << endl;

    }
    return 0;
}
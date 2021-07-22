#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;

using ll = long long;

bool check(string &s,set<string> &m);

int main() {
    ll t;
    cin >> t;
    while (t--){
        ll n;
        string s;
        cin >> n;
        cin >> s;
        vector<string> g(n);
        set<string>suf;
        for (int i = 0;i < n;i++){
            cin >> g[i];
            for (int j = 0;j < g[i].size();j++){
                suf.insert(g[i].substr(j,g[i].size() - j));
            }
        }

        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for (int i = 0;i < s.size();i++){
            for (int j = 0;j < s.size();j++){
                if (suf.find(s.substr(i,j - i)) != suf.end()){
                    if (i == 0)
                        dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[´]
                    }
                }
            }
        }

    }
    return 0;
}

bool check(string &s,set<string> &m){
return m.find(s) != m.end();
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<ll>wgt(26);
    for (int i = 0;i < 26;i++){
        cin >> wgt[i];
    }

    string s;
    cin >> s;
    vector<ll>prefSum(s.size());
    vector<unordered_map<ll,vector<ll>>>letters(26);
    for (int i = 0;i < s.size();i++){
        if (i == 0) {
            prefSum[0] = wgt[s[0] - 'a'];
            letters[s[0] -'a'][prefSum[0]].push_back(0);
        }
        else{
            prefSum[i] = prefSum[i - 1] + wgt[s[i] -'a'];
            letters[s[i]-'a'][prefSum[i]].push_back(i);
        }
    }

    ll ans = 0;

    for (int i = s.size()-1;i > 0;i--){
        ll letter = s[i] -'a';
        ll cnt = lower_bound(letters[letter][prefSum[i - 1]].begin(),letters[letter][prefSum[i - 1]].end(),i) - letters[letter][prefSum[i - 1]].begin();
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}

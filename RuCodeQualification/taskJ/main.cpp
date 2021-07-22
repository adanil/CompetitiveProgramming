#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    string word;
    map<string,ll> mp;
    for (int i = 0;i < s.size();i++){
        if (s[i] != ',')
            word += s[i];
        else{
            string name;
            int j = 0;
            string price;
            ll cost;
            while (word[j] != ':'){
                name += word[j];
                j++;
            }
            j++;
            while (j < word.size()){
                price += word[j];
                j++;
            }
            cost = stoi(price);
            mp[name] = cost;
            word.clear();
        }
    }
    string name;
    int j = 0;
    string price;
    ll cost;
    while (word[j] != ':'){
        name += word[j];
        j++;
    }
    j++;
    while (j < word.size()){
        price += word[j];
        j++;
    }
    cost = stoi(price);
    mp[name] = cost;
//    for (auto it = mp.begin();it != mp.end();it++){
//        cout << it->first << ' ' << it->second << endl;
//    }

    string combo;
    cin >> combo;
    ll ans = 1000000000000000;
    word.clear();
    ll curr = 0;
    for (int i = 0;i < combo.size();i++){
        if (combo[i] != '&' && combo[i] != '|')
            word += combo[i];
        else if(combo[i] == '&'){
            curr = max(curr,mp[word]);
            word.clear();
        }
        else{
            curr = max(curr,mp[word]);
            word.clear();
            ans = min(curr,ans);
            curr = 0;
        }
    }
    curr = max(curr,mp[word]);
    word.clear();
    ans = min(curr,ans);
    curr = 0;
    cout << ans << endl;
    return 0;
}
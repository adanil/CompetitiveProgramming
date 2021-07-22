#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using ll = long long;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll>a(n);
    for (auto &el : a)
        cin >> el;
    unordered_map<ll,int>mp;
    int k = 0;
    vector<pair<int,int>>ans;
    int l = 0,r = 0;
    for (int i = 0;i < n;i++){
        if (mp[a[i]] == 0){
            mp[a[i]]++;
        }
        else{
            mp.clear();
            ans.emplace_back(l + 1,i + 1);
            l = i+1;
            k++;
        }
    }
    if (k == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << k << endl;
    if (l != n){
        for (int i = 0;i + 1 < ans.size();i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
        cout << ans[ans.size() - 1].first << ' ' << n << endl;
    }
    else{
        for (int i = 0;i < ans.size();i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}
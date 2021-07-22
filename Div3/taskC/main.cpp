#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        set<int> a;
        map<int,int> mp;
        int maxSkill = 1;
        for (int i = 0;i < n;i++){
            int q;
            cin >> q;
            a.insert(q);
            if (mp.find(q) != mp.end()){
                mp[q]++;
                if (mp[q] > maxSkill)
                    maxSkill = mp[q];
            } else
                mp[q] = 1;

        }
        int ans;
        int uniq = a.size();
        if (uniq == maxSkill)
            uniq--;
        ans = min(uniq,maxSkill);
        cout << ans << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

struct serv{
    ll cap;
    bool lowVolt;
    ll ind;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<serv>s(n);
    for (int i = 0;i < n;i++){
        cin >> s[i].cap >> s[i].lowVolt;
        s[i].ind = i + 1;
    }
    ll ans = 0;
    ll countLow = 0;
    sort(s.begin(),s.end(),[](serv &a,serv &b){
        return a.cap > b.cap;
    });
    ll totalCap = 0;
    ll i = 0;
    set<ll>ansList;
    while (totalCap < m){
        totalCap += s[i].cap;
        ansList.insert(s[i].ind);
        ans++;
        i++;
    }
    i--;
    for (ll j = 0;j < n;j++){
        if (s[j].lowVolt){
            if (ansList.count(s[j].ind) != 0){
                countLow++;
            }
            else{
                while(i > 0 && s[i].lowVolt)
                    i--;
                if (!s[i].lowVolt){
                    if (totalCap - s[i].cap + s[j].cap >= m) {
                        totalCap = totalCap - s[i].cap + s[j].cap;
                        countLow++;
                        ansList.erase(s[i].ind);
                        ansList.insert(s[j].ind);
                        i--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    cout << ans << ' ' << countLow << endl;
    for (auto it = ansList.begin();it != ansList.end();it++){
        cout << *it << ' ';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll ans = 0;
    int repair = 1;
    vector<pair<ll,ll>>take; //first - stonks | second - pos
    for (int i = 0;i < n;i++){
        ll gold;
        cin >> gold;
        if (ans + gold - repair > ans){
            ans += (gold - repair);
            take.push_back(pair<ll,ll>(gold - repair,take.size() + 1));
            repair++;
        }
    }
    ll cnt = take.size();

    ll cntPrevDeleted = 0;
    for (int i = 0;i < take.size();i++){
        if (take[i].first + cntPrevDeleted < take.size() - take[i].second){
            ans -= take[i].first;
            ans -= cntPrevDeleted;
            ans += take.size() - take[i].second;
            cntPrevDeleted++;
        }
    }

    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long ;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>>l(m);
    ll sum = 0;
    for (ll i = 0;i < m;i++){
        cin >> l[i].first;
        sum += l[i].first;
        l[i].second = i;
    }
    if (sum < n){
        cout << -1 << endl;
        return 0;
    }


    //sort(l.begin(),l.end(),[](pair<ll,ll>a ,pair<ll,ll>b){return a > b;});


    vector<ll>ans(m);
    ll q = sum - n;
    ll prev = -1;
    ll currPos = 0;
    for (ll i = 0;i < m;i++){
        if (i == 0){
            prev = l[i].first;
            ans[l[i].second] = 1;
            currPos = l[i].first + 1;
        }
        else{
            ll is = min(q,prev-1);
            q -= is;
            currPos -= is;
            if (currPos > n - l[i].first + 1){
                cout << -1 << endl;
                return 0;
            }
            prev = l[i].first;
            ans[l[i].second] = currPos;
            currPos += l[i].first;
        }

    }
    for (ll i = 0;i < ans.size();i++)
        cout << ans[i] << ' ';
    cout << endl;



    return 0;
}
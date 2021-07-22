#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
ll INF = 1e9 + 1;

ll solve(){
    srand(time(NULL));
    vector<ll>a(6);
    ll mina = INF,maxa = -1;
    for (int i = 0;i < 6;i++) {
        cin >> a[i];
        mina = min(a[i],mina);
        maxa = max(a[i],maxa);
    }
    map<int,set<ll>>mp;
    int n;
    cin >> n;
    vector<ll>b(n);
    ll minb = INF,maxb = -1;
    ll minLad,maxLad;
    for (int i = 0;i < n;i++){
        cin >> b[i];
//        b[i] = (rand() % 100) + maxa;
//        cout << b[i] << ' ';
        for (int j = 0;j < 6;j++){
            mp[j].insert(b[i] - a[j]);
        }
        minb = min(b[i],minb);
        maxb = max(b[i],maxb);
    }
    cout << endl;
    ll ans = INF;

    ll ansmx = INF;
    ll ansmn = -1;
    for (int i = 0;i < 6;i++){
        ansmx = *(--mp[i].end());
        for (int j = 0;j < 6;j++) {
            ansmn = *(mp[j].begin());
            ans = min(ans,abs(ansmx - ansmn));
        }
    }
    if (n == 1)
        ans = b[0] - maxa;
    return ans;
}


ll test(){

    vector<ll>a(6);
    a = {1,2,3,4,5,6};
    int n;
    cin >> n;
    vector<ll>b(n);

    ll ans = INF;
    for (int i = 0;i < 6;i++){
        for (int j = 0;j < 6;j++){

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);

    cout << solve() << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;


ll binpow(ll a, ll pw, ll md) {
    if (pw == 0)
        return 1;
    if (pw % 2 == 0) {
        ll tmp = binpow(a, pw / 2, md) % md;
        return (tmp * tmp) % md;
    } else {
        return ((binpow(a, pw - 1, md) % md) * a) % md;
    }
}

vector<ll> powers;
vector<ll>r;
ll mxPow = 0;

vector<ll> stringHashing(const string &s, ll a, ll mdb) {
    vector<ll> result(s.size());
    result[0] = s[0];
    for (int i = 1; i < s.size(); i++) {
        result[i] = (result[i - 1] + s[i] * powers[i]);
    }
    return move(result);
}

ll substrHash(int a, int b, ll mdb, const vector<ll> &myHash) {
    if (a == 0)
        return myHash[b];
    ll diff = (myHash[b] - myHash[a - 1]);
    ll result = ((diff) * r[a]); //binpow(powers[a],mdb-2,mdb)
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a = 3517;
//    ll mdb = 972663749;
//    powers.resize(2001);
//    powers[0] = 1;
//    for (int i = 1;i < 2001;i++)
//        powers[i] = (powers[i - 1] * a);
//    r.resize(2001);
//    r[1] = binpow(powers[1],mdb-2,mdb);
//    for (int i=2; i< 2001; ++i)
//        r[i] = (r[i - 1] * r[1])%mdb;

    unordered_set<ll> ans;
    string tmp = "prspopsactjvetqq";
    string t;
    cin >> t;

    string bg,en;

    cin >> bg >> en;
//    if (bg.size() > t.size() || en.size() > t.size())
//    {
//        cout << 0 << endl;
//        return 0;
//    }

//    vector<ll> hashT = stringHashing(t,a,mdb);
//    ll hashBG = stringHashing(bg,a,mdb)[bg.size() - 1];
//    ll hashEN = stringHashing(en,a,mdb)[en.size() - 1];
    int tsz = t.size();
    int bgsz = bg.size();
    int ensz = en.size();

    vector<bool>strt(2001);
    vector<bool>endd(2001);
    for (int i = 0;i < tsz;i++){
        if (t.substr(i,bgsz) == bg)
            strt[i] = 1;
        if (t.substr(i,ensz) == en)
            endd[i] = 1;
    }

    for (int i = 0;i < tsz;i++){
        if (strt[i]){
            ll hs = 0;
            for (int j = i;j < tsz - ensz + 1;j++){
                hs = hs * a + t[j];
                if (j + ensz - 1 >= i + bgsz - 1 && endd[j]) {
                    ans.insert(hs);
                }
            }
        }
    }
    cout << ans.size() << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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
//    powers[0] = 1;
    for (int i = 1; i < s.size(); i++) {
//        ll p = binpow(a, i, mdb);
//        powers[i] = p;
        result[i] = (result[i - 1] + s[i] * powers[i])% mdb;
    }
    return move(result);
}

ll substrHash(int a, int b, ll mdb, const vector<ll> &myHash) {
    if (a == 0)
        return myHash[b];
    ll diff = (myHash[b] - myHash[a - 1]);
    if (diff < 0)
        diff += mdb;
    ll result = ((diff) * r[a]) %mdb; //binpow(powers[a],mdb-2,mdb)
    return result;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a = 111;
    ll mdb = 2147483647;
    powers.resize(1000000);
    powers[0] = 1;
    for (int i = 1;i < 1000000;i++)
        powers[i] = (powers[i - 1] * a)%mdb;
    r.resize(1000000);
    r[1] = binpow(powers[1],mdb-2,mdb);
    for (int i=2; i< 1000000; ++i)
        r[i] = (r[i - 1] * r[1])%mdb;

    string s;
    cin >> s;

    vector<ll> hashS = stringHashing(s,a,mdb);

    int sz = s.size() - 2;
    bool fl = false;
    string ans = "Just a legend";

    for (;sz > 0;sz--){
        ll tmpHash = 0;
        if ((tmpHash = substrHash(0,sz - 1,mdb,hashS)) == substrHash(s.size() - sz,s.size() - 1,mdb,hashS)){
            for (int i = 1;i <= s.size() - 1 - sz;i++){
                if (substrHash(i,i + sz - 1,mdb,hashS) == tmpHash){
                    fl = true;
                    ans = s.substr(i,sz);
                    break;
                }
            }
        }
        if (fl)
            break;
    }
    cout << ans << endl;
    return 0;
}
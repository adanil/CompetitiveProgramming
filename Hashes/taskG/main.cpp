#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

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

    int n;
    cin >> n;
    string ans;
    string pr;
    string nxt;
    cin >> pr;
    ans = pr;
    vector<ll> hashPr;
    hashPr = stringHashing(ans,a,mdb);
    hashPr.resize(1000000);
//    cout << hashPr.size() << endl;
    for (int i = 1;i < n;i++){
        cin >> nxt;
        vector<ll> hashNxt = stringHashing(nxt,a,mdb);
        bool fl = false;
        for (int j = nxt.size() - 1;j >= 0;j--){
            if (j > ans.size())
                continue;
            if (substrHash(0,j,mdb,hashNxt) == substrHash(ans.size()- j - 1,ans.size() - 1,mdb,hashPr)){
                string sb = nxt.substr(j + 1,nxt.size() - j);
                for (int k = 0;k < sb.size();k++){
                    hashPr[ans.size() + k] = (hashPr[ans.size() + k - 1] + sb[k] * powers[ans.size() + k])% mdb;
                }
                ans += sb;
                fl = true;
                break;
            }
        }
        if (!fl) {
            string sb = nxt;
            for (int k = 0;k < sb.size();k++){
                hashPr[ans.size() + k] = (hashPr[ans.size() + k - 1] + sb[k] * powers[ans.size() + k])% mdb;
            }
            ans += nxt;
        }
    }
    cout << ans << endl;
    return 0;
}
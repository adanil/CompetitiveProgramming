#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>

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
    ifstream fin("bacon.in");
    ofstream fout("bacon.out");
    fin.tie(NULL);
    fout.tie(NULL);

    ll a = 137;
//    ll mdb = 2147483647;
    for (ll mdb = 1e18;mdb < 1e19;mdb++){
    powers.resize(2001);
    powers[0] = 1;
    for (int i = 1; i < 2001; i++)
        powers[i] = (powers[i - 1] * a) % mdb;
    r.resize(2001);
    r[1] = binpow(powers[1], mdb - 2, mdb);
    for (int i = 2; i < 2001; ++i)
        r[i] = (r[i - 1] * r[1]) % mdb;


    string s = "aaba";
//    fin >> s;
    // for (int i = 0;i < 1000;i++)
    //     s += "cac";
    // cout << s.size() << endl;
    vector<ll> hs;

    vector<ll> hashS = stringHashing(s, a, mdb);

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++)
            hs.push_back(substrHash(i, j, mdb, hashS));
    }
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    if (hs.size() == 8) {
        cout << mdb << endl;
//        break;
    }
}




    return 0;
}
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

    int n,m;
    cin >> n >> m;
    set<ll> st;
    string s;
    for (int i = 0;i <n;i++){
        cin >> s;
        st.insert(stringHashing(s,a,mdb)[s.size() - 1]);
    }
    for (int i = 0;i < m;i++){
        bool fl = false;
        cin >> s;
        vector<ll> hashS = stringHashing(s,a,mdb);
        ll hsR = hashS[s.size() - 1];
        ll check1,check2;
        for (int j = 0;j < s.size();j++){
            if (s[j] == 'a'){
                ll hs = (hsR - ('a' * powers[j]))%mdb;
                check1 = (hs + 'b' * powers[j])%mdb;
                check2 = (hs + 'c' * powers[j])%mdb;
                if (st.count(check1) != 0 || st.count(check2) != 0){
                    fl = true;
                    break;
                }
            }
            else if (s[j] == 'b'){
                ll hs = (hsR - ('b' * powers[j]))%mdb;
                check1 = (hs + 'a' * powers[j])%mdb;
                check2 = (hs + 'c' * powers[j])%mdb;
                if (st.count(check1) != 0 || st.count(check2) != 0){
                    fl = true;
                    break;
                }
            }
            else if (s[j] == 'c'){
                ll hs = (hsR - ('c' * powers[j]))%mdb;
                check1 = (hs + 'a' * powers[j])%mdb;
                check2 = (hs + 'b' * powers[j])%mdb;
                if (st.count(check1) != 0 || st.count(check2) != 0){
                    fl = true;
                    break;
                }
            }
        }
        if (fl)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    cout.flush();
    return 0;
}
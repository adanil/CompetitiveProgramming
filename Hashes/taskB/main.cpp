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

bool isPalindrome(const vector<ll> &hashS, const vector<ll> &hashRev, int a, int b, ll mdb) {
    if (a == b)
        return true;
    int sR = (a + b - 1) / 2;
    int revL = hashRev.size() - b - 1;
    int revR = (revL + (revL + (b - a) - 1))/2;
    ll hashOne = substrHash(a, sR, mdb, hashS);
    ll hashTwo = substrHash(revL,revR,mdb,hashRev);
    return hashOne == hashTwo;
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
    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;
        mxPow = s.size();
        string srev = s;
        reverse(srev.begin(), srev.end());
        vector<ll> hashS = stringHashing(s, a, mdb);
        vector<ll> hashRev = stringHashing(srev, a, mdb);

//        cout << isPalindrome(hashS,hashRev,3,5,mdb) << endl;

        ll ansLen = 0;
        ll prefSufLen = 0;
        string ansS;
        bool pref = false;
        for (ll i = 0;i < s.size()/2;i++){
            if (hashS[i] == hashRev[i]){
                ansLen = max(ansLen,i + 1);
            }
            else
                break;
        }
        prefSufLen = ansLen;
        int start =  prefSufLen;
        for (ll i = start;i < s.size() - prefSufLen;i++){
            if (isPalindrome(hashS,hashRev,start,i,mdb)){
                if (i + 1 > ansLen){
                    ansLen = i + 1;
                    pref = true;
                }
            }
        }
        for (ll i = s.size() - 1 - start;i > start;i--){
            if (isPalindrome(hashS,hashRev,i,s.size() - 1 - start,mdb)){
                ll tmp = s.size() - i;
                if ((tmp) > ansLen){
                    ansLen = tmp;
                    pref = false;
                }
            }
        }
        if (pref){
            for (int i = 0;i < ansLen;i++)
                cout << s[i];
            if (prefSufLen != 0){
                for (int i = s.size() - prefSufLen;i < s.size();i++)
                    cout << s[i];
            }
            cout << endl;
        }
        else{
            if (prefSufLen != 0){
                for (int i = 0;i < prefSufLen;i++)
                    cout << s[i];
            }
            for (int i = s.size() - ansLen;i < s.size();i++)
                cout << s[i];
            cout << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    string pref,post;
    ll ind = -1;
//    if (m < n){
//        cout << "NO" << endl;
//        return 0;
//    }
    for (int i = 0;i < n;i++){
        if (s[i] == '*') {
            ind = i;
            break;
        }
        pref.push_back(s[i]);
    }

    if (ind == -1){
        if (s == t){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        return 0;
    }
    else{
        if (m < n-1){
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = ind + 1; i < n; i++) {
            post.push_back(s[i]);
    }
    bool fl = true;
    for (int i = 0;i < pref.size();i++){
        if (t[i] != pref[i]){
            fl = false;
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 0;i < post.size();i++){
        if (t[m-1+i-post.size() + 1] != post[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
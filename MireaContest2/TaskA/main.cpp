#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll n, q;
    cin >> n;
    set<string> real;
    ll i = 0;
    string buffer;
    while (getline(cin, buffer) && i < n) {
        if (i != 0)
            real.insert(buffer);
        i++;
    }
    if (i > 0)
        real.insert(buffer);


    cin >> q;
    string s;
    ll t = 0;
    while (getline(cin, s) && t < q) {
        if (t != 0) {
            if (real.find(s) != real.end())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        t++;
    }
    if (t > 0) {
        if (real.find(s) != real.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
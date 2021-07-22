#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> mp;
    bool ok = false;
    for (int i = 0;i < s.size();i++){
        mp[s[i]]++;
        if (mp[s[i]] >= 2)
            ok = true;
    }
    if (n == 1)
        ok = true;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef vector<int> lnum;
const int base = 1000*1000*1000;
using ll = long long;

int main() {
    lnum a;
    string s;
    ll b;
    cin >> s;
    cin >> b;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));

    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int (cur / b);
        carry = int (cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    cout << carry << endl;
    return 0;
}
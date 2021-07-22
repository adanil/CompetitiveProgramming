#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<int>a(k);
    string s;
    cin >> s;
    for (auto c:s)
        a[c - 'A']++;

    int m = *min_element(a.begin(),a.end());
    int ans = 0;
    cout << m * k << endl;


    return 0;
}
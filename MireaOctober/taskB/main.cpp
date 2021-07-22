#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0;i < 10;i++){
        if (((1 << i) & n) != 0)
            s += '1';
        else
            s += '0';
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}
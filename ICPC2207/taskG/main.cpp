#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<set<int>>plates(n);

    string s = "ab";
    char c = 'c';
    s.push_back(c);
    cout << s << endl;

    cout << "1 1 0" << endl;
    int curr = 1;
    int empt = 1;
    int type = 1;
    int cnt = n * (n-1) - 1;
    int t = 0;
    while (cnt > 0){
        if (curr + 1 <= n){
            curr++;
            if (plates[empt - 1].count(curr - 1) != 0)
                continue;
            cout << curr << ' ' << curr << ' ' << empt << endl;
            plates[empt - 1].insert(curr - 1);
            empt = curr;

            cnt--;
        }
        else{
            curr = 1;
            if (plates[empt - 1].count(curr - 1) != 0)
                continue;
            cout << curr << ' ' << curr << ' ' << empt << endl;
            plates[empt - 1].insert(curr - 1);
            empt = curr;

            cnt--;
        }
//        t++;
    }
    cout << 0 << ' ' << type << ' ' << empt << endl;

    return 0;
}
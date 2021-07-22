#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll INF = 1000000001;
int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    ll maxEl = -INF,maxElInd = -1;
    int i = 0;
    for (auto &el : a){
        cin >> el;
        if (el > maxEl){
            maxEl = el;
            maxElInd = i;
        }
        i++;
    }
    cout << (maxElInd - 1 + n) % n + 1 << ' ' << maxElInd + 1 << ' ' << (maxElInd + 1)%n + 1 << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    vector<ll>items;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++)
        cin >> b[i];

    for (int i = 0;i < n;i++)
        cout << a[i] << ' ';



    return 0;
}
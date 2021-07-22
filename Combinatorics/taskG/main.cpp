#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0;i < n;i++)
        cin >> a[i];
    vector<ll>ans(n);
    ll as = 0;
    for (int i = 0;i < n;i++){
        ans[i] = a[i] + i * (a[i] - 1);
        as += ans[i];
    }

    cout << as << endl;
    return 0;
}
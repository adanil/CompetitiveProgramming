#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0;i < n;i++)
        cin >> a[i];
    ll ans = 1;
    ll prev = a[0];
    char fl = 2; // 0 - убывающая 1 - возрастающая 2 - неопределенно

    for (int i = 1; i < n; i++) {
        if (a[i] == prev){
            continue;
        }
        else if (a[i] != prev && fl == 2){
            if (a[i] > prev)
                fl = 1;
            else
                fl = 0;
            ans++;
            prev = a[i];
        }
        else if(a[i] != prev && fl == 1){
            if (a[i] > prev)
                prev = a[i];
            else{
                ans++;
                fl = 0;
                prev = a[i];
            }
        }
        else if (a[i] != prev && fl == 0){
            if (a[i] < prev)
                prev = a[i];
            else{
                ans++;
                fl = 1;
                prev = a[i];
            }
        }
        else
            continue;

    }
    cout << ans << endl;
    return 0;
}
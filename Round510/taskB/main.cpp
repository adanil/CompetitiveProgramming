#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 10000000000000;

int main() {
    ll n;
    cin >> n;
    map<string,ll>sok;
    for (int i = 0;i < n;i++){
        ll c;
        string v;
        cin >> c >> v;
        sort(v.begin(),v.end());
        if (sok.count(v) == 0)
            sok[v] = c;
        else
            sok[v] = min(sok[v],c);
    }

    ll ans = INF;
    if (sok.count("ABC") != 0)
        ans = sok["ABC"];

    if (sok.count("AB") != 0 && sok.count("AC") != 0)
        ans = min(ans,sok["AB"] + sok["AC"]);
    if (sok.count("AB") != 0 && sok.count("BC") != 0)
        ans = min(ans,sok["AB"] + sok["BC"]);

    if (sok.count("AC") != 0 && sok.count("BC") != 0)
        ans = min(ans,sok["AC"] + sok["BC"]);

    if (sok.count("BC") != 0 && sok.count("AC") != 0)
        ans = min(ans,sok["BC"] + sok["AC"]);

    if (sok.count("AB") != 0 && sok.count("C") != 0)
        ans = min(ans,sok["AB"] + sok["C"]);

    if (sok.count("BC") != 0 && sok.count("A") != 0)
        ans = min(ans,sok["BC"] + sok["A"]);

    if (sok.count("AC") != 0 && sok.count("B") != 0)
        ans = min(ans,sok["B"] + sok["AC"]);

    if (sok.count("A") != 0 && sok.count("B") != 0 && sok.count("C"))
        ans = min(ans,sok["B"] + sok["A"] + sok["C"]);


    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;



    return 0;
}
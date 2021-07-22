#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}


ll INF = 1000000001;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>pl;
    vector<double>ans(n,1);
    vector<double>p(n,1);
    int q = 0;
    int tc = 0;
    for (int i = 0;i < 2*n;i++){
        char c;
        int t;
        cin >> c >> t;
        if (c == '+'){
            pl.push_back(t);
            q++;
        }
        else{
            ans[tc] *= p[tc] * (1.0/q);
            p[tc] *= 1 - (1.0/q);
//            for (int j = 0;j < pl.size();j++){
//                ans[j] += (t - pl[j]) * p[j] * (1.0/q);
//                p[j] *= 1 - (1.0/q);
//            }
            q--;
        }
    }

    for (auto el : ans)
        cout << fixed << setprecision(6)<< el << '\n';
    cout.flush();
    return 0;
}
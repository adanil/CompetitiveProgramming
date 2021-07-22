#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    long long ans = 0;
    cin >> n;
    vector<pair<long long,long long>>p(n);
    for (long long  i = 0;i < n;i++){
        long long a,b;
        cin >> a >> b;
        p[i] = make_pair(a,b);
    }


    for (long long i = n-1;i >= 0;i--){
        long long t = 0;
        if ((p[i].first+ ans) % p[i].second != 0) {
            if ((p[i].first+ans) > p[i].second)
                t = p[i].second * (((p[i].first+ans) / p[i].second) + 1) - (p[i].first + ans);
            else
                t = p[i].second - (p[i].first + ans);
        }
        ans += t;
        //p[i].first += t;

    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;


int main() {
    const int maxn = 2*1e6 + 1;
    vector<bool> primes(maxn,true);
    primes[0] = false;primes[1] = false;
    for (int i = 2;i*i < maxn;i++){
        if (primes[i]){
            for (int j = i*i;j < maxn;j += i)
                primes[j] = false;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll>a;
    vector<ll>ans;
    for (int i = 0;i < n;i++) {
        int b;
        cin >> b;
        if (b == 1)
            ans.push_back(b);
        else
            a.push_back(b);
    }
    if (ans.size() == 0){
        for (int i = 0;i < a.size();i++){
            for (int j = i + 1;j < a.size();j++){
                if (primes[a[i] + a[j]]){
                    ans.push_back(a[i]);ans.push_back(a[j]);
                    cout << ans.size() << endl;
                    for (auto el :ans)
                        cout << el << ' ';
                    return 0;
                }
            }
        }
        for (int i = 0;i < a.size();i++){
                ans.push_back(a[i]);
                cout << ans.size() << endl;
                for (auto el :ans)
                    cout << el << ' ';
                return 0;
        }
    }
    else if (ans.size() == 1) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                if (primes[a[i] + a[j]]) {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                    cout << 2 << endl;
                    cout << a[i] << ' ' << a[j];
                    return 0;
                }
            }
        }
        for (int i = 0;i < a.size();i++ ){
            if (primes[1 + a[i]]){
                ans.push_back(a[i]);
                cout << ans.size() << endl;
                for (auto el :ans)
                    cout << el << ' ';
                return 0;
            }
        }
    }
    else if (!a.empty()){
        for (int i = 0;i < a.size();i++ ){
            if (primes[1 + a[i]]){
                ans.push_back(a[i]);
                cout << ans.size() << endl;
                for (auto el :ans)
                    cout << el << ' ';
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto el :ans)
        cout << el << ' ';









    return 0;
}
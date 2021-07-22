#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    set<int> a;
    int k,ans,k2;
    bool fl = false;
    bool fl2 = false;
    for (int i = 0;i < n/2 + 2;i++){
        int el;
        cin >> el;
        a.insert(el);
        if (a.count(el) > 1 && !fl){
            fl = true;
            k = a.count(el);
        }
        else if(a.count(el) > 1 && fl){
            fl2 = true;
            k2 = a.count(el);
        }
        else if (a.count(el) > 1 && fl && fl2){
            if (a.count(el) == k){
                k = k;
            }
            else if (a.count(el) == k2)
                k = k2;
        }
    }
    for (auto it = a.begin();it != a.end();it++){
        if (a.count(*it) != k)
            ans = *it
    }
    return 0;
}
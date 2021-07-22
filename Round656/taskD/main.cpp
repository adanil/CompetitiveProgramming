#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
int n;
string s;
ll func (int l,int r,int level){
    if (l + 1 == r){
        if (s[l] == 'a' + level)
            return 0;
        else
            return 1;
    }
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = l;i <(l+r)/2;i++){
        if (s[i] != 'a' + level)
            ans1++;
    }
    for (int i = (l+r)/2;i <r;i++){
        if (s[i] != 'a' + level)
            ans2++;
    }

    ans1 += func((l + r)/2,r,level + 1);
    ans2 += func(l,(l + r)/2,level + 1);
    return min(ans1,ans2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        cout << func(0,n,0) << endl;

    }
    return 0;
}
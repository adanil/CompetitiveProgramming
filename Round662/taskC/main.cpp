#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        set<int>sw;
        map<int,int>cnt;
        int n;
        cin >> n;
        int mx = 0;
        int mxCnt = 0;
        for (int i = 0;i < n;i++){
            int el;
            cin >> el;
            sw.insert(el);
            cnt[el]++;
            mx = max(mx,cnt[el]);
        }
        for (auto it = cnt.begin();it != cnt.end();it++){
            if (it->second == mx)
                mxCnt++;
        }
        cout << (n - mx - 1)/(mx - 1) << endl;


    }
    return 0;
}
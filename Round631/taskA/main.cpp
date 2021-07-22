#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long ;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        set<int> tmp;
        for (int i = 0;i < n;i++){
            int q;
            cin >> q;
            tmp.insert(q);
        }
        int ans = 0;
        for (int i = 1;i < 201;i++){
            if (tmp.find(i) == tmp.end()) {
                if (x == 0)
                    break;
                x--;
            }
            ans = i;
        }


        cout << ans << endl;
    }
    return 0;
}
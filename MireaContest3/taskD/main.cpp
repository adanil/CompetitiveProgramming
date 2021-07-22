#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

//sumTree
int main() {

    int t;
    cin >> t;
    while(t--){
        int n,q;
        map<ll,ll> mp; //{ind - sum}
        cin >> n >> q;

        for (int i = 0;i < q;i++){
            char c;
            cin >> c;
            if (c == 's'){
                ll u;
                cin >> u;
                cout << mp[u] << endl;

            }
            else{
                ll u,x;
                cin >> u >> x;
                mp[u] += x;
                while(u != 1){
                    u /= 2;
                    mp[u] += x;
                }

            }
        }

    }


    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;
ll INF = 1e9 + 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int>cost;
    int n;
    cin >> n;
    static vector<int>ans(1e5,-1);
    static vector<pair<char,int>>data(2*1e5);
    int bal = 0;
    int cntpl = 0;
    set<int>left;
    for (int i = 0;i < 2*n;i++){
        char c;
        int el = -1;
        cin >> c;

        if (c == '+'){
            cntpl++;
            bal++;
            left.insert(cntpl);
        }
        else{
            bal--;
            cin >> el;
            if (bal < 0){
                cout << "NO" << endl;
                return 0;
            }
            int curr = *(--left.end()) - 1;
            ans[curr] = el;
            left.erase(--left.end());
        }
        data[i] = {c,el};
    }

    int q = 0;
    for (int i = 0;i < 2*n;i++){
        if (data[i].first == '+'){
            cost.insert(ans[q]);
            q++;
        }
        else{
            if (*cost.begin() != data[i].second){
                cout << "NO" << endl;
                return 0;
            }
            else{
                cost.erase(cost.begin());
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0;i < n;i++)
        cout << ans[i] << ' ';
    return 0;
}
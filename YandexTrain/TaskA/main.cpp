#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    string root;
    cin >> root;
    vector<string>rules(m);
    for (int i = 0;i < m;i++){
        cin >> rules[i];
    }
    int k;
    cin >> k;
    for (int i = 0;i < k;i++){
        string check;
        cin >> check;
        vector<bool>pos(n,false);
        vector<bool>usedRules(m,false);
        for (int j = 0;j < m;j++){
            bool fl = true;
            for (int q = 0;q < n;q++){
                if (!pos[q] && rules[j][q] != '-' && rules[j][q] == check[q])
                    continue;
                else if (!pos[q] && rules[j][q] != '-' && rules[j][q] != check[q])
                    fl = false;
            }
            if (fl){
                for (int q = 0;q < n;q++){
                    if (!pos[q] && rules[j][q] != '-' && rules[j][q] == check[q])
                        pos[q] = true;
                }
            }
        }

        bool fl = true;
        for (int j = 0;j < n;j++){
            if (pos[j] == false && check[j] != root[j]){
                fl = false;
                break;
            }
        }
        if (fl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}
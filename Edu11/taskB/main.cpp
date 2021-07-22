#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;

    vector<vector<int>>bus(n,vector<int>(4,0));

    int cnt = 0;

    int currR = 0;
    while(m > 0){
        if (bus[currR][0] == 0)
            bus[currR][0] = ++cnt;
        else if (bus[currR][3] == 0) {
            bus[currR][3] = ++cnt;
            if (currR < n - 1)
                currR++;
            else
                currR = 0;
        }
        else if (bus[currR][1] == 0){
            bus[currR][1] = ++cnt;
        }
        else if (bus[currR][2] == 0){
            bus[currR][2] = ++cnt;
            if (currR < n - 1)
                currR++;
            else
                currR = 0;
        }
        m--;
    }

    for (int i = 0;i < n;i++){
        if (bus[i][1] != 0)
            cout << bus[i][1] << ' ';
        if (bus[i][0] != 0)
            cout << bus[i][0] << ' ';
        if (bus[i][2] != 0)
            cout << bus[i][2] << ' ';
        if (bus[i][3] != 0)
            cout << bus[i][3] << ' ';
    }


    return 0;
}
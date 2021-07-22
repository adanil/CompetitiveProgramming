#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<char>>table(n,vector<char>(n));
    vector<vector<bool>>used(n,vector<bool>(n,false));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            cin >> table[i][j];
        }
    }
    int r,c;
    cin >> r >> c;
    r--;
    c--;
    int ans = -1;
    while(((r < n && r >= 0) && (c < n && c >= 0)) && (table[r][c] != '.') && (!used[r][c])){
        used[r][c] = true;
        if (table[r][c] == 'N'){
            r--;
        }
        else if (table[r][c] == 'S'){
            r++;
        }
        else if (table[r][c] == 'E'){
            c++;
        }
        else if (table[r][c] == 'W'){
            c--;
        }
    }

    if ((r >= n || r < 0) || (c >= n || c < 0)){
        cout << 0 << endl;
    }
    else if (used[r][c]){
        cout << -1 << endl;
    }
    else{
        cout << r+1 << ' ' << c+1 << endl;
    }

    return 0;
}
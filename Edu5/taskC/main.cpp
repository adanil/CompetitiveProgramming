#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 100000000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<char>>table(n,vector<char>(m));

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++)
            cin >> table[i][j];
    }

    vector<vector<int>>used(n,vector<int>(m,0));
    map<int,int>mp;

    int compNumb = 1;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (table[i][j] == '*') {
                if (i > 0 && table[i - 1][j] == '.' && !used[i - 1][j]) {
                    int ans = 0;
                    queue<pair<int, int>> q;
                    q.push({i - 1, j});
                    while (!q.empty()) {
                        auto[x, y] = q.front();
                        q.pop();
                        ans++;
                        used[x][y] = compNumb;
                        if (x > 0) {
                            if (!used[x - 1][y] && table[x - 1][y] == '.') {
                                q.push({x - 1, y});
                                used[x - 1][y] = compNumb;
                            }
                        }
                        if (x + 1 < n) {
                            if (!used[x + 1][y] && table[x + 1][y] == '.') {
                                q.push({x + 1, y});
                                used[x + 1][y] = compNumb;
                            }
                        }
                        if (y > 0) {
                            if (!used[x][y - 1] && table[x][y - 1] == '.') {
                                q.push({x, y - 1});
                                used[x][y - 1] = compNumb;
                            }
                        }
                        if (y + 1 < m) {
                            if (!used[x][y + 1] && table[x][y + 1] == '.') {
                                q.push({x, y + 1});
                                used[x][y + 1] = compNumb;
                            }
                        }
                    }
                    mp[compNumb] = ans % 10;
                    compNumb++;
                }
                if (i + 1 < n && table[i + 1][j] == '.' && !used[i + 1][j]) {
                    int ans = 0;
                    queue<pair<int, int>> q;
                    q.push({i + 1, j});
                    while (!q.empty()) {
                        auto[x, y] = q.front();
                        q.pop();
                        ans++;
                        used[x][y] = compNumb;
                        if (x > 0) {
                            if (!used[x - 1][y] && table[x - 1][y] == '.') {
                                q.push({x - 1, y});
                                used[x - 1][y] = compNumb;
                            }
                        }
                        if (x + 1 < n) {
                            if (!used[x + 1][y] && table[x + 1][y] == '.') {
                                q.push({x + 1, y});
                                used[x + 1][y] = compNumb;
                            }
                        }
                        if (y > 0) {
                            if (!used[x][y - 1] && table[x][y - 1] == '.') {
                                q.push({x, y - 1});
                                used[x][y - 1] = compNumb;
                            }
                        }
                        if (y + 1 < m) {
                            if (!used[x][y + 1] && table[x][y + 1] == '.') {
                                q.push({x, y + 1});
                                used[x][y + 1] = compNumb;
                            }
                        }
                    }
                    mp[compNumb] = ans % 10;
                    compNumb++;
                }
                if (j > 0 && table[i][j - 1] == '.' && !used[i][j - 1]) {
                    int ans = 0;
                    queue<pair<int, int>> q;
                    q.push({i , j - 1});
                    while (!q.empty()) {
                        auto[x, y] = q.front();
                        q.pop();
                        ans++;
                        used[x][y] = compNumb;
                        if (x > 0) {
                            if (!used[x - 1][y] && table[x - 1][y] == '.') {
                                q.push({x - 1, y});
                                used[x - 1][y] = compNumb;
                            }
                        }
                        if (x + 1 < n) {
                            if (!used[x + 1][y] && table[x + 1][y] == '.') {
                                q.push({x + 1, y});
                                used[x + 1][y] = compNumb;
                            }
                        }
                        if (y > 0) {
                            if (!used[x][y - 1] && table[x][y - 1] == '.') {
                                q.push({x, y - 1});
                                used[x][y - 1] = compNumb;
                            }
                        }
                        if (y + 1 < m) {
                            if (!used[x][y + 1] && table[x][y + 1] == '.') {
                                q.push({x, y + 1});
                                used[x][y + 1] = compNumb;
                            }
                        }
                    }
                    mp[compNumb] = ans % 10;
                    compNumb++;
                }
                if (j + 1 < m && table[i][j + 1] == '.' && !used[i][j + 1]) {
                    int ans = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j + 1});
                    while (!q.empty()) {
                        auto[x, y] = q.front();
                        q.pop();
                        ans++;
                        used[x][y] = compNumb;
                        if (x > 0) {
                            if (!used[x - 1][y] && table[x - 1][y] == '.') {
                                q.push({x - 1, y});
                                used[x - 1][y] = compNumb;
                            }
                        }
                        if (x + 1 < n) {
                            if (!used[x + 1][y] && table[x + 1][y] == '.') {
                                q.push({x + 1, y});
                                used[x + 1][y] = compNumb;
                            }
                        }
                        if (y > 0) {
                            if (!used[x][y - 1] && table[x][y - 1] == '.') {
                                q.push({x, y - 1});
                                used[x][y - 1] = compNumb;
                            }
                        }
                        if (y + 1 < m) {
                            if (!used[x][y + 1] && table[x][y + 1] == '.') {
                                q.push({x, y + 1});
                                used[x][y + 1] = compNumb;
                            }
                        }
                    }
                    mp[compNumb] = ans % 10;
                    compNumb++;
                }
            }
        }
    }

//    cout <<"map" <<endl;
//    for (auto it : mp){
//        cout << it.first << ' ' << it.second << endl;
//    }
//    cout << "-------" << endl;
//    for (int i = 0;i < n;i++){
//        for (int j = 0;j < m;j++)
//            cout << used[i][j] << ' ';
//        cout << endl;
//    }

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (table[i][j] == '.')
                cout << '.';
            else{
                set<int>st;
                int lans = 0;
                if (i > 0) {

                    if (table[i-1][j] == '.')
                        st.insert(used[i-1][j]);
                }
                if (i + 1 < n) {

                    if (table[i + 1][j] == '.')
                        st.insert(used[i+1][j]);
                }
                if (j > 0) {

                    if (table[i][j - 1] == '.')
                        st.insert(used[i][j - 1]);
                }
                if (j + 1 < m) {

                    if (table[i][j + 1] =='.')
                        st.insert(used[i][j+1]);
                }
                for (auto it : st){
                    lans += mp[it];
                }
                cout << (lans + 1)%10;
            }
        }
        cout << '\n';
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;


const ll INF = 1000000000000000;


int main() {
    int test;
    cin >> test;
    while(test--){
        pair<int,int> t1,t2;
        bool fl = false;
        int h,w;
        cin >> h >> w;
        vector<vector<char>>table(h+4,vector<char>(w + 4));
        for (int i = 0;i < w + 4;i++){
            table[0][i] = '*';
            table[1][i] = '.';
            table[h + 3][i] = '*';
            table[h + 2][i] = '.';
        }
        for (int i = 0;i < h + 4;i++){
            table[i][0] = '*';
            table[i][h + 3] = '*';
            table[i][1] = '.';
            table[i][h + 2] = '.';
        }
        for (int i = 0;i < h;i++){
            for (int j = 0;j < h;j++){
                cin >> table[i + 2][j + 2];
                if (table[i + 2][j + 2] == '$'){
                    if (!fl) {
                        t1 = {i + 2, j + 2};
                        fl = true;
                    }
                    else
                        t2 = {i + 2,j + 2};
                }
            }
        }

        vector<vector<ll>>values(h + 4,vector<ll>(w + 4,INF));
        vector<vector<pair<int,int>>>pr(h + 4,vector<pair<int,int>>(w + 4,{-1,-1}));
        for (int i = 0;i < w + 4;i++){
            values[0][i] = -1;
            values[1][i] = 0;
            values[h + 3][i] = -1;
            values[h + 2][i] = 0;
        }
        for (int i = 0;i < h + 4;i++){
            values[i][0] = -1;
            values[i][h + 3] = -1;
            values[i][1] = 0;
            values[i][h + 2] = 0;
        }

        for (int i = 1;i < h + 3;i++){
            for (int j = 1;j < w + 3;j++){
                if (table[i - 1][j] == '#') {
                    if (values[i - 1][j] > values[i][j] + 1)
                        pr[i - 1][j] = {i,j};
                    values[i - 1][j] = min(values[i - 1][j], values[i][j] + 1);
                }
                else if (table[i - 1][j] == '.') {
                    if (values[i - 1][j] > values[i][j])
                        pr[i - 1][j] = {i,j};
                    values[i - 1][j] = min(values[i - 1][j], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i + 1][j] == '#') {
                    if (values[i + 1][j] > values[i][j] + 1)
                        pr[i + 1][j] = {i,j};
                    values[i + 1][j] = min(values[i + 1][j], values[i][j] + 1);
                }
                else if (table[i + 1][j] == '.') {
                    if (values[i + 1][j] > values[i][j])
                        pr[i + 1][j] = {i,j};
                    values[i + 1][j] = min(values[i + 1][j], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i][j - 1] == '#') {
                    if (values[i][j - 1] > values[i][j] + 1)
                        pr[i][j - 1] = {i,j};
                    values[i][j - 1] = min(values[i][j - 1], values[i][j] + 1);
                }
                else if (table[i][j - 1] == '.') {
                    if (values[i][j - 1] > values[i][j])
                        pr[i][j - 1] = {i,j};
                    values[i][j - 1] = min(values[i][j - 1], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i][j + 1] == '#') {
                    if (values[i][j + 1] > values[i][j] + 1)
                        pr[i][j + 1] = {i,j};
                    values[i][j + 1] = min(values[i][j + 1], values[i][j] + 1);
                }
                else if (table[i][j + 1] == '.') {
                    if (values[i][j + 1] > values[i][j])
                        pr[i][j + 1] = {i,j};
                    values[i][j + 1] = min(values[i][j + 1], values[i][j]);
                }
                else{
                    continue;
                }

            }
        }
        ll ans = values[t1.first][t1.second];
        auto curr = t1;
        while (pr[curr.first][curr.second].first != -1){
            curr = pr[curr.first][curr.second];
            if (table[curr.first][curr.second] == '#')
                table[curr.first][curr.second] = '.';
        }



        values = vector<vector<ll>>(h + 4,vector<ll>(w + 4,INF));
        for (int i = 0;i < w + 4;i++){
            values[0][i] = -1;
            values[1][i] = 0;
            values[h + 3][i] = -1;
            values[h + 2][i] = 0;
        }
        for (int i = 0;i < h + 4;i++){
            values[i][0] = -1;
            values[i][h + 3] = -1;
            values[i][1] = 0;
            values[i][h + 2] = 0;
        }

        for (int i = 1;i < h + 3;i++){
            for (int j = 1;j < w + 3;j++){
                if (table[i - 1][j] == '#') {
                    if (values[i - 1][j] > values[i][j] + 1)
                        pr[i - 1][j] = {i,j};
                    values[i - 1][j] = min(values[i - 1][j], values[i][j] + 1);
                }
                else if (table[i - 1][j] == '.') {
                    if (values[i - 1][j] > values[i][j])
                        pr[i - 1][j] = {i,j};
                    values[i - 1][j] = min(values[i - 1][j], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i + 1][j] == '#') {
                    if (values[i + 1][j] > values[i][j] + 1)
                        pr[i + 1][j] = {i,j};
                    values[i + 1][j] = min(values[i + 1][j], values[i][j] + 1);
                }
                else if (table[i + 1][j] == '.') {
                    if (values[i + 1][j] > values[i][j])
                        pr[i + 1][j] = {i,j};
                    values[i + 1][j] = min(values[i + 1][j], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i][j - 1] == '#') {
                    if (values[i][j - 1] > values[i][j] + 1)
                        pr[i][j - 1] = {i,j};
                    values[i][j - 1] = min(values[i][j - 1], values[i][j] + 1);
                }
                else if (table[i][j - 1] == '.') {
                    if (values[i][j - 1] > values[i][j])
                        pr[i][j - 1] = {i,j};
                    values[i][j - 1] = min(values[i][j - 1], values[i][j]);
                }
                else{
                    continue;
                }
                if (table[i][j + 1] == '#') {
                    if (values[i][j + 1] > values[i][j] + 1)
                        pr[i][j + 1] = {i,j};
                    values[i][j + 1] = min(values[i][j + 1], values[i][j] + 1);
                }
                else if (table[i][j + 1] == '.') {
                    if (values[i][j + 1] > values[i][j])
                        pr[i][j + 1] = {i,j};
                    values[i][j + 1] = min(values[i][j + 1], values[i][j]);
                }
                else{
                    continue;
                }

            }
        }

        ans += values[t2.first][t2.second];

        cout << ans << endl;


    }
    return 0;
}
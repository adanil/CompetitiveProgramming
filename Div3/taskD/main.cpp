#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        vector<vector<int>>sud(9,vector<int>(9,0));
        string s;
        set<int>st;
        for (int i = 0;i < 9;i++){
            cin >> s;
            for (int j =0;j < 9;j++){
                sud[i][j] = s[j] - 48;
            }
        }
        vector<vector<int>>ans(9,vector<int>(9,0));
        ans = sud;
        int colStart = -1;
        int i = colStart;
        for (int j = 0;j < 9;j++) {
            if (j % 3 == 0){
                i = colStart+1;
                colStart++;
            }
                int q = sud[i][j];
                    if (q == 9)
                        q = 1;
                    else
                        q++;
                ans[i][j] = q;
                //cout << i << ' ' << j << endl;
                i += 3;


        }



        for (int i = 0;i < 9;i++){
            for (int j = 0;j < 9;j++)
                cout << ans[i][j];
            cout << endl;
        }




    }

    return 0;
}
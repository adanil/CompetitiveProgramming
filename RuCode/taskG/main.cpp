#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    vector<vector<char>> msg(17,vector<char>(23));
    char c;
    for (int i = 0;i < 17;i++) {
        for (int j = 0;j < 23;j++) {
            cin >> c;
            msg[i][j] = c;
        }
    }
    for (int i = 0;i < 23;i++){
        if (msg[16][i] == 'x'){
            for (int )
        }
    }

    return 0;
}
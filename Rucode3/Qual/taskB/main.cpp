#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string wk,wl,bk;
    cin >> wk >> wl >> bk;
    int wk_c,wk_r,wl_c,wl_r,bk_c,bk_r;
    wk_c = wk[0] -'a' + 1;
    wk_r = wk[1] - '1' + 1;

    wl_c = wl[0] -'a' + 1;
    wl_r = wl[1] - '1' + 1;

    bk_c = bk[0] -'a' + 1;
    bk_r = bk[1] - '1' + 1;


    vector<vector<char>> table(10,vector<char>(10,'c')); //l - атака ладьи //k - атака короля //c - чисто
    for (int i = 0;i < 10;i++) {
        table[0][i] = 'l';
        table[9][i] = 'l';
        table[i][0] = 'l';
        table[i][9] = 'l';
    }
    for (int i = wl_c;i > 0;i--){
        if (wl_r == wk_r && i == wk_c)
            break;
        table[wl_r][i] = 'l';
    }
    for (int i = wl_c;i < 10;i++){
        if (wl_r == wk_r && i == wk_c)
            break;
        table[wl_r][i] = 'l';
    }

    for (int i = wl_r;i > 0;i--){
        if (wl_c == wk_c && i == wk_r)
            break;
        table[i][wl_c] = 'l';
    }
    for (int i = wl_r;i < 10;i++){
        if (wl_c == wk_c && i == wk_r)
            break;
        table[i][wl_c] = 'l';
    }

    table[wl_r][wl_c] = 'c';

    table[wk_r][wk_c + 1] = 'k';
    table[wk_r][wk_c - 1] = 'k';
    table[wk_r + 1][wk_c] = 'k';
    table[wk_r - 1][wk_c] = 'k';

    table[wk_r + 1][wk_c + 1] = 'k';
    table[wk_r + 1][wk_c - 1] = 'k';
    table[wk_r - 1][wk_c - 1] = 'k';
    table[wk_r - 1][wk_c + 1] = 'k';

//    for (int i = 0;i < 10;i++){
//        for (int j = 0;j < 10;j++){
//            cout << table[i][j] << ' ';
//        }
//        cout << endl;
//    }


    if (table[bk_r][bk_c] == 'k'){
        cout << "Strange" << endl;
        return 0;
    }

    bool isAttacked = false;
    if (table[bk_r][bk_c] == 'l')
        isAttacked = true;

    bool canStep = false;

    if (table[bk_r][bk_c + 1] == 'c' || table[bk_r][bk_c - 1] == 'c' || table[bk_r + 1][bk_c] == 'c' ||
    table[bk_r - 1][bk_c] == 'c' || table[bk_r + 1][bk_c + 1] == 'c' || table[bk_r + 1][bk_c - 1] == 'c' ||
    table[bk_r - 1][bk_c - 1] == 'c' || table[bk_r - 1][bk_c + 1] == 'c')
        canStep = true;

    if (!isAttacked && canStep){
        cout << "Normal" << endl;
    }
    else if (isAttacked && canStep){
        cout << "Check" << endl;
    }
    else if (!isAttacked && !canStep){
        cout << "Stalemate" << endl;
    }
    else if (isAttacked && !canStep) {
        cout << "Checkmate" << endl;
    }

    return 0;
}
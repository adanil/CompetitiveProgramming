#include <iostream>
#include <vector>
#include <string>
#include <utility>


using namespace std;

int main() {
    const int notAttack = 0;
    const int kingAttack = 1;
    const int ladAttack = 2;
    const int ladAndKingAttack = 3;


    pair<int,int> wk,wl,bk;

    string s;
    cin >> s;
    int vert = s[0] - 96;
    int hor = s[1] - 48;
    wk = make_pair(vert-1,hor-1);

    cin >> s;
    vert = s[0] - 96;
    hor = s[1] - 48;
    wl = make_pair(vert-1,hor-1);

    cin >> s;
    vert = s[0] - 96;
    hor = s[1] - 48;
    bk = make_pair(vert-1,hor-1);


    vector<vector<int>> table(8,vector<int>(8,notAttack));

//учесть клетку с ладьей - нет

    for (int i = wk.first - 1;i < wk.first + 2;i++){
        for (int j = wk.second - 1;j < wk.second + 2;j++){
            if (i >= 0 && i < 8 && j >= 0 && j < 8){
                table[i][j] = kingAttack;
            }
        }
    }

    //table[wl.first][wl.second] = notAttack;
    //table[wk.first][wk.second] = notAttack;


    int i = wl.first;
    int j = wl.second;
    while (i-1 >= 0){
        if (i == wk.first && j == wk.second)
            break;
        i--;
        if (table[i][j] == kingAttack)
            table[i][j] = ladAndKingAttack;
        else
            table[i][j] = ladAttack;

    }


    i = wl.first;
    j = wl.second;
    while (i+1 < 8){
        if (i == wk.first && j == wk.second)
            break;
        i++;
        if (table[i][j] == kingAttack)
            table[i][j] = ladAndKingAttack;
        else
            table[i][j] = ladAttack;

    }

    i = wl.first;
    j = wl.second;
    while (j-1 >= 0){
        if (i == wk.first && j == wk.second)
            break;
        j--;
        if (table[i][j] == kingAttack)
            table[i][j] = ladAndKingAttack;
        else
            table[i][j] = ladAttack;

    }

    i = wl.first;
    j = wl.second;
    while (j+1 < 8){
        if (i == wk.first && j == wk.second)
            break;
        j++;
        if (table[i][j] == kingAttack)
            table[i][j] = ladAndKingAttack;
        else
            table[i][j] = ladAttack;

    }

    //table[wk.first][wk.second] = notAttack;

    if (table[bk.first][bk.second] == kingAttack || table[bk.first][bk.second] == ladAndKingAttack){
        cout << "Strange" << endl;
        return 0;
    }

    if (table[bk.first][bk.second] == notAttack){
        bool canStep = false;
        for (i = bk.first - 1;i < bk.first + 2;i++){
            for (j = bk.second - 1;j < bk.second + 2;j++){
                if (i >= 0 && i < 8 && j >= 0 && j < 8) {
                    if (i == bk.first && j == bk.second)
                        continue;
                    if (table[i][j] == notAttack)
                        canStep = true;
                }
            }
        }
        if (canStep){
            cout << "Normal" << endl;
            return 0;
        }
        else{
            cout << "Stalemate" << endl;
            return 0;
        }
    }
    else{
        bool canStep = false;
        for (i = bk.first - 1;i < bk.first + 2;i++){
            for (j = bk.second - 1;j < bk.second + 2;j++){
                if (i >= 0 && i < 8 && j >= 0 && j < 8) {
                    if (i == bk.first && j == bk.second)
                        continue;
                    if (table[i][j] == notAttack)
                        canStep = true;
                }
            }
        }
        if (canStep){
            cout << "Check" << endl;
            return 0;
        }
        else{
            cout << "Checkmate" << endl;
            return 0;
        }

    }


    return 0;
}
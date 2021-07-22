#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;

int main() {
    int x = 567;
    int y = x;
    int n;
    cin >> n;
    vector<pair<char,int>>p(n);
    vector<short>state(10,-1); //1 - в 1 0 - в 0 -1 - не трогать
    for (int i = 0;i < n;i++){
        cin >> p[i].first >> p[i].second;
        int bit = 0;
        if (p[i].first == '|') {
            x |= p[i].second;
            int d = p[i].second;
            while (d != 0) {
                if ((d & 1) == 1){
                    state[bit] = 1;
                }
                d >>= 1;
                bit++;
            }
        }
        else if (p[i].first == '&'){
            x &= p[i].second;
            int d = p[i].second;
            while (bit < 10) {
                if ((d & 1) == 0){
                    state[bit] = 0;
                }
//                if (d == 0)
//                    state[bit] = 0;
                d >>= 1;
                bit++;
            }
        }
        else {
            x ^= p[i].second;
            int d = p[i].second;
            while (d != 0) {
                if ((d & 1) == 1 && state[bit] == 1){
                    state[bit] = 0;
                }
                else if ((d & 1) == 1 && state[bit] == 0){
                    state[bit] = 1;
                }
                else if ((d & 1) == 1 && state[bit] == -1){
                    state[bit] = 3;
                }
                else if ((d & 1) == 1 && state[bit] == 3)
                    state[bit] = -1;
                d >>= 1;
                bit++;
            }
        }
    }

    int dna = 1023;
    int ro = 0;
    int rox = 0;
    for (int i = 0;i < 10;i++){
        if (state[i] == 1){
            int tmp = 1;
            for (int j = 0;j < i;j++)
                tmp <<= 1;
            ro |= tmp;
        }
        else if (state[i] == 0){
            int tmp = 1;
            for (int j = 0;j < i;j++)
                tmp <<= 1;
            dna ^= tmp;
        }
        else if (state[i] == 3){
            int tmp = 1;
            for (int j = 0;j < i;j++)
                tmp <<= 1;
            rox |= tmp;
        }
    }
    int cnt = 0;
    if (dna != 0) {
        cnt++;
        y &= dna;
    }
    if (ro != 0) {
        y |= ro;
        cnt++;
    }
    if (rox != 0) {
        y ^= rox;
        cnt++;
    }
    cout << 3 << endl;
//    if (dna)
        cout << "& " << dna << endl;
//    if (ro)
        cout << "| " << ro << endl;
//    if (rox)
        cout << "^ " << rox << endl;

//    cout << x << ' ' << y << endl;

    return 0;
}
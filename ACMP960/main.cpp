#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string t = "abc";
    string s;
    cin >> s;
    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    //0 - a
    //1 - b
    //2 - c

    vector<vector<long long>> d(3,vector<long long>(s.size(),0));
    for (long long i = 0;i < s.size();i++){
        if (i != 0){
            d[0][i] = d[0][i-1];
            d[1][i] = d[1][i-1];
            d[2][i] = d[2][i-1];
        }
        if (s[i] == 'a'){
            d[0][i] += 1;
        }
        else if (s[i] == 'b'){
            if (i != 0){
                d[1][i] = d[0][i] + d[1][i-1];
            }
        }
        else if (s[i] == 'c'){
            if (i != 0){
                d[2][i] = d[1][i] + d[2][i-1];
            }
        }
        else
            continue;
    }

    cout << d[2][s.size()-1] << endl;


    return 0;
}
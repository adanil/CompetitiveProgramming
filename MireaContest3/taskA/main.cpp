#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
using ll = long long;
using ull = unsigned long long;




int main() {
    int t;
    cin >> t;
    while(t--){
        bool ext = false;
        int xs,ys,xt,yt;
        cin >> xs >> ys >> xt >> yt;
        string ans;


        ans += "D";
        for (int i = 0;i < xt - xs + 1;i++)
            ans += "R";
        for (int i = 0;i < yt - ys + 1;i++)
            ans += "U";
        ans += "L";
        ans += "U";
        for (int i = 0;i < xt - xs + 1;i++)
            ans += "L";
        for (int i = 0;i < yt - ys + 1;i++)
            ans += "D";
        ans += "R";

        for (int i = 0;i < xt - xs;i++)
            ans += "R";
        for (int i = 0;i < yt - ys;i++)
            ans += "U";
        for (int i = 0;i < xt - xs;i++)
            ans += "L";
        for (int i = 0;i < yt - ys;i++)
            ans += "D";



        cout << ans << endl;

    }

    return 0;
}
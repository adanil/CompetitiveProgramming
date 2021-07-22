#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for (auto &el : a)
        cin >> el;
    int ans = 0,startInd = 0,endInd = 0;
    int ansStart = 0;
    int curr = 0;
    int zeros = 0;
    for (int i = 0;i < n;i++){
        if (a[i] == 1){
            curr++;
        }
        else{
            curr++;
            zeros++;
            while(zeros > k && startInd < n){
                if (a[startInd] == 0)
                    zeros--;
                curr--;
                startInd++;
            }
        }
        if (curr > ans){
            ans = curr;
            endInd = i;
            ansStart = startInd;
        }
    }
    cout << ans << endl;
    if (ans == 0){
        for (int i = 0;i < n;i++)
            cout << a[i] << ' ';
    }
    else {
        for (int i = 0; i < ansStart; i++)
            cout << a[i] << ' ';
        for (int i = ansStart; i <= endInd; i++)
            cout << 1 << ' ';
        for (int i = endInd + 1; i < n; i++)
            cout << a[i] << ' ';
    }



    return 0;
}
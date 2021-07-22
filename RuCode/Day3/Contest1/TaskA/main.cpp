#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    k--;
    vector<int>used(n+1,0);
    vector<int>p(n,1);
    for (int i = 1;i < n;i++){
        p[i] = p[i-1]*i;
    }

    vector<int>ans(n);


    for (int i = 0;i < n;i++){
        for (int j = 1;j <= n;j++){
            if (!used[j]){
                if (k < p[n-i-1]){
                    ans[i] = j;
                    used[j] = 1;
                    break;
                }
                else{
                    k -= p[n-i-1];
                }
            }
        }
    }

    for (auto &i : ans){
        cout << i << ' ';
    }
    return 0;
}
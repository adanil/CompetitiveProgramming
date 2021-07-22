#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int>ans(n);
    ll sum = 1;
    int i = 1;
    int t = 1;
   while (t < n){
       sum *= 2;
       t++;
    }
   cout << sum << endl;
    return 0;
}
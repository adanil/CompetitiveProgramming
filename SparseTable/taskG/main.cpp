#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    for (int i = 0;i < n - 1;i++){
        int from,to;
        cin >> from >> to;
        from--;to--;
        g[from].push_back(to);
    }

    return 0;
}
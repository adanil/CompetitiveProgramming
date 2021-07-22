#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0;i < n;i++){
        cin >> p[i];
    }

    vector<int>d(n,1);
    for (int i = 1;i < n;i++){
        for (int j = 0;j < i;j++)
            if (p[i] > p[j])
                d[i] = max(d[j] + 1,d[i]);
    }

    cout << *max_element(d.begin(),d.end()) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll s(int n,int k){
    if (n == 0 && k == 0)
        return 1;
    else if (k == 0 || n == 0)
        return 0;
    else
        return s(n-1,k-1) + (n-1)*s(n-1,k);
}

int main() {
    int n;
    cin >> n;
    cout << s(n,2) << endl;
    return 0;
}
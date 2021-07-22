#include <iostream>
using namespace std;

double binPow(double x, int n)
{
    double power = 1.0;
    while (n){
        if (n & 1){
            power *= x;
        }
        n >>= 1;
        x *= x;
    }
    return power;
}


int main() {
    int n;
    cin >> n;
    string ans = to_string(binPow(2,n));
    string res;
    int i = 0;
    while (ans[i] != '.'){
        res.push_back(ans[i]);
        i++;
    }
    cout << res << endl;
    return 0;
}
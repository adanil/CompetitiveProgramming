#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

long double C (int n, int k) {
    long double res = 1;
    for (int i=1; i<=k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

#define EPS 0.000001

int main() {
    int a,n1,n2,t;
    long double p;
    cin >> a >> n1 >> n2 >> t >> p;
    p /= 100;

    if (n2 == 0){
        cout << 0 << endl;
        return 0;
    }
    if (n2 >= t){
        cout << 1.0000000 << endl;
        return 0;
    }
    long double ans = 0;
    long double b = 0;
   for (int i = 0;i < n2;i++){
       ans += C(t-1,i) * pow(p,i)*pow(1-p,t-1-i);
   }

   cout << fixed << setprecision(7) << ans << endl;



    return 0;
}
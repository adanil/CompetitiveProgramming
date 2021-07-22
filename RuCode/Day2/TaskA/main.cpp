#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
using ld = long double;

struct Vec{
    ld x;
    ld y;
};

ld vecmul(Vec a,Vec b){
    return (a.x * b.y - b.x * a.y);
}
ld scalMul(Vec a,Vec b){
    return (a.x * b.x + a.y * b.y);
}

int main() {
    Vec a,b;
    cin >>a.x >> a.y >> b.x >> b.y;
    ld ans = atan2(vecmul(a,b),scalMul(a,b));
    ans = abs(ans);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
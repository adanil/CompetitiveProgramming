#include <iostream>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int h,m;
    char c;
    cin >> h >> c >> m;
    int a;
    cin >> a;
    ll mins = h*60 + m + a;
    cout << setfill('0') << setw(2)<< (mins/60)%24 << ':' << setw(2)<< mins%60 << endl;
    return 0;
}
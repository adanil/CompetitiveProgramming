#include <iostream>
#include <vector>
#include <cmath>

using ull = unsigned long long;
using namespace std;

int main() {
    ull n,q;
    cin >> n >> q;
    for (int i = 0;i < q;i++){
        ull p;
        cin >> p;
        p--;

        ull l,r;
        l = 0;
        r = pow(2,n) - 1;
        ull copn = n;
        ull ploc = p;
        ull pglob = p;
        while (copn > 1){
            if ((ploc + 1)%2 == 0){
                l = (l + r)/2 + 1;
                ploc = (ploc + 1)/2 - 1;
                pglob = l + ploc;
            } else{
                r = (l + r)/2;
                ploc = ploc/2;
                pglob = l + ploc;
            }
            copn--;
        }
        cout << pglob + 1 << ' ';

    }
    return 0;
}
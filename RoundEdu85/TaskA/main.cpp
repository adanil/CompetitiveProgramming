#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p,c,pprev = 0,cprev = 0;
        bool fl = false;
        for (int i = 0;i < n;i++) {
            cin >> p >> c;
            if (c > p || pprev > p || cprev > c)
                fl = true;
            else if(p - pprev < c - cprev)
                fl = true;
            pprev = p;
            cprev = c;
        }
        if (fl)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;


    }
    return 0;
}
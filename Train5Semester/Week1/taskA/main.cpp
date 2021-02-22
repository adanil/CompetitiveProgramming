#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll>h(n);
    for (auto &el : h)
        cin >> el;
    sort(h.begin(),h.end());
    h.erase(unique(h.begin(),h.end()),h.end());
    n = h.size();
    cout << setprecision(6);
    cout << fixed;
    if (n > 3) {
        vector<double> ansCoord(4,-1);

        double l = 0,r = h[h.size() - 1];
        double ans =r;
//        bool valid = true;


        while(l + 0.5 < r){
            r = round(r);
            l = floor(l);
            vector<double>tmpCoord(4,-1);
            double mid = (l + r)/2;
            int houses = 0;
            int curr = 0;
            int frst = 0;
            int station = 1;
            while (curr < n) {
                while (h[frst] + mid*2 >= h[curr] && curr < n) {
                    houses++;
                    curr++;
                }
                tmpCoord[station] = min(h[frst] + mid,(double)h[h.size() - 1]);
                frst = curr;
                station++;
                if (station == 4){
                    break;
                }
            }
            if (houses == n || tmpCoord[3] + mid >= h[h.size() - 1]){
                if (tmpCoord[2] == -1)
                    tmpCoord[2] = h[h.size() - 1];
                if (tmpCoord[3] == -1)
                    tmpCoord[3] = h[h.size() - 1];
                r = mid;
                ans = min(ans,mid);
                ansCoord = tmpCoord;
            }
            else{
                l = mid;
            }

        }
        cout << ans << endl;
        cout << ansCoord[1] << ' ' << ansCoord[2] << ' ' << ansCoord[3] << endl;
    }
    else if (n == 3){
        cout << 0 << endl;
        cout << h[0] << ' ' << h[1] << ' ' << h[2] << endl;
    }
    else if (n == 2){
        cout << 0 << endl;
        cout << h[0] << ' ' << h[1] << ' ' << h[1] << endl;
    }
    else{
        cout << 0 << endl;
        cout << h[0] << ' ' << h[0] << ' ' << h[0] << endl;
    }




    return 0;
}

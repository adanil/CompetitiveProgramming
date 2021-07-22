#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

ll ans = 0;
vector<ll> p;
static int n;
static ll l,r;


void process(const vector<char> &&bm) {
    int cnt = 0;
    ll tmpL = l;
    ll tmpR= r;
    for (int i = 0;i < n;i++){
        if (bm[i]){
            cnt++;
            tmpL /= p[i];
            tmpR /= p[i];
        }
    }
    if ((cnt & 1) == 0)
        ans -= (tmpR - tmpL);
    else
        ans += (tmpR - tmpL);


}

void nextPerm(vector<char> &&bm, int cnt,int pos) {
    for (int i = pos; i < n; i++) {
        if (bm[i])
            continue;
        bm[i] = 1;
        if (cnt > 1)
            nextPerm(move(bm), cnt - 1,i + 1);
        else {
            process(move(bm));
        }
        bm[i] = 0;
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> l >> r >> n;
    l--;
    p.resize(n);
    vector<char> bm;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    n = p.size();
    bm.resize(n,0);

    for (int i = 0;i < n;i++)
        nextPerm(move(bm),i + 1,0);

    cout << ans << endl;


    return 0;
}
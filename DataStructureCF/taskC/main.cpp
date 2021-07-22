#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <algorithm>




using namespace std;
using ll = long long;

using std::cin;
using std::cout;
using std::vector;
using ll = long long;
using vi = vector<int>;
using vell = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vell>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
#define isz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define forx(x, n) for(int x = 0; x < n; ++x)
#define forx1(x, n) for(int x = 1; x <= n; ++x)
#define fill(v, n) for(int i = 0; i < n; ++i) cin >> v[i];
const ll mod = 2971215073;



int main()
{
    ll T, n, m;
    cin >> T >> n >> m;
    vell a_(m), b_(m);
    forx(i, m) cin >> a_[i] >> b_[i];
    ll curT = 0;
    forx(i, m) curT += b_[i];
    if (curT > T)
    {
        cout << "No\n";
        return 0;
    }

    vell gaps_min(m + 1, -1);
    vell gaps_max(m + 1, -1);

    bool ok = true;
    ll l = 0;
    ll r;
    forx(i, m + 1)
    {
        if(i < m) r = a_[i];
        else r = n + 1;
        if (r - l - 1 <= 0)
        {
            if (i < m) l = a_[i];
            continue;
        }
        ll a, b;
        ll dl;
        if (l == 0)
        {
            b = b_[i];
            dl = a_[i] - 1;
            if (b - dl <= 0) gaps_min[i] = (1 + b) * b / 2;
            else gaps_min[i] = (b - dl + b) * (dl + 1) / 2;
            gaps_min[i] -= b;
            gaps_max[i] = (b + b + dl) * (dl + 1) / 2;
            gaps_max[i] -= b;
        }
        else if (l == a_[m - 1])
        {
            a = b_[i - 1];
            dl = n - a_[i - 1];
            if (a - dl <= 0) gaps_min[i] = (1 + a) * a / 2;
            else gaps_min[i] = (a - dl + a) * (dl + 1) / 2;
            gaps_max[i] = (a + a + dl) * (dl + 1) / 2;
            gaps_min[i] -= a;
            gaps_max[i] -= a;
        }
        else
        {
            a = b_[i - 1];
            b = b_[i];

            if (a > b) std::swap(a, b); // a <= b
            dl = r - l - 1;
            if (b - a > dl + 1)
            {
                ok = false;
                break;

            }
            else if (b - a == dl + 1)
            {
                gaps_min[i] = gaps_max[i] = (a + b) * dl / 2;
            }
            else
            {
                ll local_min;
                ll local_max;
                ll dlup = dl - (b - a);
                local_min = std::max(0LL, a - (dlup + 1) / 2);
                ll sum_l = (local_min + a - 1) * (a - 1 - local_min + 1) / 2;
                ll sum_r = (local_min + b - 1) * (b - 1 - local_min + 1) / 2;
                gaps_min[i] = sum_l + sum_r - local_min;
                local_max = b + (dlup + 1) / 2;
                sum_l = (local_max + a + 1) * (local_max - (a + 1) + 1) / 2;
                sum_r = (local_max + b + 1) * (local_max - (b + 1) + 1) / 2;
                gaps_max[i] = sum_l + sum_r - local_max;
            }
        }
        if(i < m) l = a_[i];
    }
    if (!ok)
    {
        cout << "No\n";
        return 0;
    }
    for (auto &x : gaps_min) if (x != -1) curT += x;
    if (curT > T)
    {
        cout << "No\n";
        return 0;
    }
    for (auto &x : gaps_min) if (x != -1) curT -= x;
    for (auto &x : gaps_max) if (x != -1) curT += x;
    if (curT < T)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}
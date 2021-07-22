#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::vector;
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define all(x) (x).begin(), (x).end()
#define isz(x) int((x).size())
#define forx(x, n) for(int x = 0; x < n; ++x)
#define range(x, a, b) for(int x = a; x <= b; ++x)

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - 1LL * (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= 1LL * c / g;
    y0 *= 1LL * c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

const auto ready = []()
{
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    return true;
}();

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll b, d; cin >> b >> d;
        ll x0, y0, g;
        find_any_solution(d, b, 1LL * b * b, x0, y0, g);
        ll t_low, t_up;
        if (1LL * x0 * g % b == 0) t_low = -1LL * x0 * g / b + 1;
        else  t_low = (-1LL * x0 * g + b - 1) / b;

        if (1LL * y0 * g % d == 0) t_up = 1LL * y0 * g / d - 1;
        else
        {
            t_up = (1LL * y0 * g) / d;
            if (t_up < 0) --t_up;
        }
        cout << (t_up - t_low + 1) << "\n";
    }
    return 0;
}
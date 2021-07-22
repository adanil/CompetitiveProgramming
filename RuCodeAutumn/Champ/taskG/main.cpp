#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <numeric>
#include <iterator>
#include <queue>
#include <map>
#include <random>
#include <assert.h>
#include <chrono>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using ll = long long;
using real = long double;
using u64t = uint64_t;
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
const ll mod = 1e9 + 7;

ll fast_multip(ll a, ll b, ll m)
{
    if (!a || !b) return 0;
    if (b == 1) return a;
    if (a == 1) return b;
    if (b % 2 == 0) {
        long long t = fast_multip(a, b / 2, m);
        return (2 * t) % m;
    }
    return (fast_multip(a, b - 1, m) + a) % m;
}

ll fast_pow(ll a, ll b, ll m)
{
    if (b == 0)
        return (m == 1) ? 0 : 1;
    if (b % 2 == 0) {
        ll t = fast_pow(a, b / 2, m);
        return fast_multip(t, t, m) % m;
    }
    return (fast_multip(fast_pow(a, b - 1, m), a, m)) % m;
}

ll inv(ll a)
{
    return fast_pow(a, mod - 2, mod);
}

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

template<class A, class B>
void remin(A &a, const B &b)
{
    a = (a < b) ? a : b;
}

template<class A, class B>
void remax(A &a, const B &b)
{
    a = (a > b) ? a : b;
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
    ll n; cin >> n;
    if (n == 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    vell factors;
    std::map<ll, ll> mp;
    ll kek = n;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (kek % i == 0)
        {
            ++mp[i];
            factors.push_back(i);
            kek /= i;
        }
    }
    if (kek > 1)
    {
        ++mp[kek];
        factors.push_back(kek);
    }
    if (factors.size() == 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    ll sum = 0;
    for (ll x : factors) sum += x;
    ll bestSum = n;
    ll ones = bestSum - sum;
    cout << mp.size() + ((ones) ? 1 : 0) << "\n";
    if (ones) cout << 1 << " " << ones << "\n";
    for (auto &x : mp) cout << x.first << " " << x.second << "\n";
    return 0;
}
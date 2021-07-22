
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using std::cin;
using std::cout;
using std::endl;
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
const int mod = (int)(1e9 + 7);

template<typename A, typename B>
void remin(A& a, const B& b)
{
    a = std::min(a, b);
}

template<typename A, typename B>
void remax(A& a, const B& b)
{
    a = std::max(a, b);
}

const auto ready = []()
{
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    return true;
}();

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

struct move
{
    int from;
    int to;
    int type;
};

const int shift = 32;
const int sz = 95;

void make_edges(vpii& edges, vi& used)
{
    int ptr_l = -1;
    int ptr_r = -1;
    int real_l = -1;
    int real_r = -1;
    forx(i, sz)
    {
        if (used[i] || (i > 32 - shift && i < 48 - shift) || (i > 57 - shift && i < 65 - shift)
        || (i > 90 - shift && i < 97 - shift) || (i > 122 - shift && i < 126 - shift))
        {
            if (used[i] && real_l == -1)
                real_l = i;
            if (real_l != -1 && real_r == -1 )
                real_r = i;
            if (used[i] && real_r != -1)
                real_r = i;
            if (ptr_l == -1) ptr_l = i;
            ptr_r = i;
        }
        else if(ptr_l != -1)
        {
            if (real_r == -1)
                real_r = i;
            if (real_r - real_l < 2)
                edges.push_back({real_l,real_r});
            else if (real_l != -1) {
                int r;
                ptr_r < real_r ? r = ptr_r : r = real_r;
                edges.push_back({ptr_l, r});
            }
            ptr_l = -1;
            real_l = -1;
            real_r = -1;
        }

    }
//    if (used[sz - 1])
//    {
//        edges.push_back({ ptr_l, ptr_r });
//        ptr_l = -1;
//    }
}


void make_inv_edges(vpii& edges, vi& used)
{
    int ptr_l = -1;
    int ptr_r = -1;
    int real_l = -1;
    int real_r = -1;
    forx(i, sz)
    {
        if (!used[i] || (i > 32 - shift && i < 48 - shift) || (i > 57 - shift && i < 65 - shift)
            || (i > 90 - shift && i < 97 - shift) || (i > 122 - shift && i < 126 - shift))
        {
            if (!used[i] && real_l == -1 && !((i > 32 - shift && i < 48 - shift) || (i > 57 - shift && i < 65 - shift)
                                              || (i > 90 - shift && i < 97 - shift) || (i > 122 - shift && i < 127 - shift))) {
                real_l = i;
            }
            if (real_l != -1 && real_r == -1 )
                real_r = i;
            if (!used[i] && real_r != -1 && !((i > 32 - shift && i < 48 - shift) || (i > 57 - shift && i < 65 - shift)
                                              || (i > 90 - shift && i < 97 - shift) || (i > 122 - shift && i < 127 - shift)))
                real_r = i;
            if (ptr_l == -1) ptr_l = i;
            ptr_r = i;
        }
        else if(real_l != -1)
        {
            if (real_r == -1)
                real_r = i;
            if (real_r - real_l < 2)
                edges.push_back({real_l,real_r});
            else if (real_l != -1) {
                int r;
                int l;
                real_l > ptr_l ? l = real_l : l = ptr_l;
                ptr_r < real_r ? r = ptr_r : r = real_r;
                edges.push_back({l, r});
            }
            ptr_l = -1;
            real_l = -1;
            real_r = -1;
        }

    }
    if (!used[sz - 1])
    {
        edges.push_back({ real_l, real_r });
        ptr_l = -1;
    }
}

void make_string(vpii& edges, vector<std::string>& vec)
{
    for (auto& x : edges)
    {
        std::string s;
        if (x.second - x.first < 2) {
            for (int i = x.first; i <= x.second; i++)
                s.push_back((char) (i + shift));
        }
        else{
            if ((char)(x.first + shift) == '0')
                s.push_back('!');
            else if ((char)(x.first + shift) == 'A')
                s.push_back(':');
            else if ((char)(x.first + shift) == 'a')
                s.push_back('[');
            else
                s.push_back((char)(x.first + shift));
            s.push_back('-');
            s.push_back((char)(x.second + shift));
        }
        vec.push_back(s);
    }
}



void make_inv_string(vpii& edges, vector<std::string>& vec)
{
    for (auto& x : edges)
    {
        std::string s;
        if (x.second - x.first < 2) {
            for (int i = x.first; i <= x.second; i++)
                s.push_back((char) (i + shift));
        }
        else{
            s.push_back((char)(x.first + shift));
            s.push_back('-');
//            if ((char)(x.second + shift) == '9')
//                s.push_back('@');
//            else if ((char)(x.second + shift) == 'Z')
//                s.push_back(char(96));
//            else if ((char)(x.second + shift) == 'z')
//                s.push_back('~');
//            else
            s.push_back((char)(x.second + shift));

        }
        vec.push_back(s);
    }
}



int main()
{
    // 32
    std::string s;
    std::getline(cin, s);
    const int n = s.size();
    vi used(sz, 0);
    forx(i, n)
    {
        ++used[s[i] - shift];
    }

    vpii e;
    vpii e2;

    make_edges(e, used);
    make_inv_edges(e2,used);

//    for (int i = e.size() - 1; i >= 0; --i)
//    {
//        char sym = e[i].first + shift;
//        if (sym == 'a') for (int j = 96 - shift; j >= 91 - shift; --j) ++used[j];
//        else if(sym == 'A') for (int j = 64 - shift; j >= 58 - shift; --j) ++used[j];
//        else if(sym == '0') for (int j = 47 - shift; j >= 33 - shift; --j) ++used[j];
//    }

//    make_edges(e2, used);

    std::vector<std::string> ans1;
    std::vector<std::string> ans2;

    make_string(e, ans1);
    make_inv_string(e2,ans2);
    std::sort(all(ans1));
    std::sort(all(ans2));
    ans1.resize(unique(ans1.begin(),ans1.end()) - ans1.begin());
    ans2.resize(unique(ans2.begin(),ans2.end()) - ans2.begin());
    std::string ans1_s;
    std::string ans2_s;
    ans1_s += '%';
    ans1_s += '[';
    for (auto& x : ans1) ans1_s += x;
    ans1_s += ']';
    ans2_s += '%';
    ans2_s += '[';
    ans2_s += '^';
    for (auto& x : ans2) ans2_s += x;
    ans2_s += ']';

    for (int i = 0;i < ans2_s.size();i++){
        if (ans2_s[i] == 31){
            ans2_s.erase(ans2_s.begin() + i);
        }
    }

    for (int i = 0;i < ans1_s.size();i++){
//        cout << ans1_s[i] << endl;
        if (ans1_s[i] == 31){
            ans1_s.erase(ans1_s.begin() + i);
        }
    }

//    cout << ans1_s.size() << ' ' << ans2_s.size() << endl;
    if (ans1_s.size() < ans2_s.size() || (ans1_s.size() == ans2_s.size() && ans1_s < ans2_s))
    {
        cout << ans2_s << endl;
        cout << ans1_s << endl;
    }
    else
    {
//        cout << ans1_s << endl;
        cout << ans2_s << endl;

    }



    return 0;
}

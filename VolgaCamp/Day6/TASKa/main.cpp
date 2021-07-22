//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
#pragma GCC optimize("Ofast")
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<vi> vvi;
typedef std::vector<vl> vvl;
typedef std::pair<int,int> pii;
typedef std::pair<int,ll> pil;
typedef std::pair<ll,int> pli;
typedef std::pair<ll,ll> pll;
typedef std::vector<std::pair<int,int>> vpii;
#define range1(n) for(int (used4range1counter) = 0; (used4range1counter) < (n); (used4range1counter)++)
#define range2(i, n) for(int (i) = 0, used4rangeEndcounter=(n); (i) < used4rangeEndcounter; (i)++)
#define range3(i, b, n) for(int (i) = (b), used4rangeEndcounter = (n); (i) < used4rangeEndcounter; (i)++)
#define range4(i, b, n, d) for(int (i) = (b), used4rangeEndcounter = (n); ((d)>0?(i) < (used4rangeEndcounter):(i)>(used4rangeEndcounter)); (i)+=(d))
#define GET_5TH_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define RANGE_MACRO_CHOOSER(...) GET_5TH_ARG(__VA_ARGS__, range4, range3, range2, range1)
#define forx(...) RANGE_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)
#define isz(x) (int)size(x)
#define all(x) std::begin(x), std::end(x)
#define fi first
#define se second
#define debug(x) std::cout << #x << " = " << x << "\n"
const auto ready = [](){std::ios_base::sync_with_stdio(false);std::cin.tie(0); std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(12);
    return 1;}();
int divCeil(int n, int d) { return d < 0 ? (n + d + 1) / d : (n + d - 1) / d; }
int sgn(int x){return x?x>0?1:-1:0;}

// Input:
template<typename T>
T input(T& a, std::istream& is = cin)
{
    is >> a;
    return a;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec)
{
    for (auto &it : vec) is >> it;
    return is;
}
template<typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {return is >> p.fi >> p.se;}
template<typename T> queue<T>& operator<<(queue<T>& q, T& x) {q.push(x); return q;}
template<typename T> queue<T>& operator>>(queue<T>& q, T& x) {x = q.front();q.pop(); return q;}


template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    forx(i, vec.size()) os << vec[i] << " ";
    return os << "\n";
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::set<T>& S)
{
    for (T el:S) os << el << " ";
    return os << "\n";
}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>& S)
{
    for (T el:S) os << el << " ";
    return os << "\n";
}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T1, typename T2, typename T3>
std::ostream& operator<<(ostream& os,const std::tuple<T1,T2,T3>& p){return os<<"("<<p.first<<", "<<p.second<<", "<<p.third<<")";}

int main()
{
    ll n, n1, sum=0, a, m, k, b, c, d, p, r, i, ans;
    while(1)
    {
        cin >> n;
        if(!n) return 0;
        vvl A(n, vl(3)), B(n);
        cin >> A;
        ans=1;
        forx(i, pow(3, n))
        {
            n1=i;
            forx(j, n)
            {
                B[j]=A[j];
                B[j].erase(B[j].begin()+(n1%3));
                n1/=3;
                if(B[j][0]>B[j][1]) swap(B[j][0], B[j][1]);
            }
            sort(all(B));
            vl Ans(n,1);
            forx(j, n-2, -1, -1) forx(k, j, n) if(B[j][1]>=B[k][1])Ans[j]=max(Ans[j], Ans[k]+1);
            forx(j, n) ans = max(ans, Ans[j]);
        }
        cout  << ans << "\n";
    }
    return 0;
}
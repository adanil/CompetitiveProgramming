//#include <bits/stdc++.h>
#include <vector>
#include <set>
#include<map>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>
//#include <bits/stdc++.h>
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
#define all(x) (std::begin(x), std::end(x))
#define fi first
#define se second
#define debug(x) std::cout << #x << " = " << x << "\n"
const auto ready = [](){std::ios_base::sync_with_stdio(false);std::cin.tie(0); std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(12);
    return 1;}();
int divCeil(int n, int d) { return d < 0 ? (n + d + 1) / d : (n + d - 1) / d; }
int sgn(int x){return x?x>0?1:-1:0;}

class Timer
{
    std::chrono::time_point<std::chrono::steady_clock> timePoint;
    size_t value;
public:
    void start() { timePoint = std::chrono::steady_clock::now(); }
    void finish()
    {
        auto curr = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(curr - timePoint);
        value = elapsed.count();
    }
    size_t operator()() const { return value; }
};

class range {
public:
    class iterator {
    public:
        iterator(int ptr=0,int delta=1): ptr(ptr),delta(delta){}
        iterator operator++() { ptr+=delta; return *this; }
        bool operator!=(const iterator & other) const { return ptr != other.ptr; }
        int operator*() const { return ptr; }
    private:
        int ptr,delta;
    };
private:
    int val, len, delta;
public:
    range(int n) : val(0),len(n),delta(1) { }
    range(int a, int b, int d = 1) : val(a), len((abs(b-a)+abs(d)-1)/abs(d)), delta(d) {if ((b-a) * 1LL * d <= 0) val = len = delta = 0;}
    iterator begin() const { return iterator(val,delta); }
    iterator end() const { return iterator(val + len * delta, delta); }
};

class residue
{
public:
    static const int Mod;
    long long val;
    residue(long long Value){val = Value<0?(-Value)%Mod: Value%Mod;if(Value<0)*(this)=*(this)*residue(Mod-1);}
    residue(){val=0;}
    residue operator+(residue A){return residue(val+A.val);}
    residue operator-(residue A){return residue(val-A.val);}
    residue operator*(residue A){return residue((val*A.val) % Mod);}
    residue operator/(residue a){return *(this)*(a^-1);}
    residue operator+(int A){return residue(val+A);}
    residue operator-(int A){return residue(val-A);}
    residue operator*(int A){return residue(val*A);}
    residue operator/(int A){return (residue(A)^(-1))*(*this);}
    residue operator+=(residue A){return val = (*this+A).val,*this;}
    residue operator*=(residue A){return val = (*this*A).val,*this;}
    residue operator-=(residue A){return val = (*this-A).val,*this;}
    residue operator/=(residue A){return val = (*this/A).val,*this;}
    residue operator^(int n){return n==-1?(*this)^ui(Mod-2):n<0?(*this^-1)^ui(-n):*this^ui(n);}
    residue operator^(ui n){return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
    residue operator^(ull n){return n?n&1?((*this**this)^(n/2))**this:(*this**this)^(n/2):residue(1);}
    residue operator^(ll n){return n==-1?(*this)^ull(Mod-2):n<0?(*this^-1)^ull(-n):*this^ull(n);}
    operator int(){return val;}
};
const int residue::Mod = 1e9+7;
std::vector<residue> fact(2, 1);
std::vector<residue> obrfact(2, 1);
residue residueC(int n, int k)
{
    int i;
    if(fact.size()<=n+1)for(((i = fact.size()), fact.resize(n+1), obrfact.resize(n+1)); i <= n; i++)fact[i] =(fact[i-1]*i), obrfact[i] = (fact[i]^(-1));
    return fact[n]*obrfact[k]*obrfact[n-k];
}
long long Cnk(int n, int k)
{
    long long Ans = 1;
    for(int i = 0; i < k; i++) Ans = Ans * (n-i)/(i+1);
    return Ans;
}
template<typename T>
class Matrix
{
public:
    std::vector<std::vector<T>> val;
    Matrix(std::vector<std::vector<T>> &v){val=v;}
    Matrix<T> operator+(Matrix<T>& A)
    {
        std::vector<std::vector<T>> Ans(val.size(), vector<T>(val[0].size()));
        range2(i, val.size())range2(j, val[0].size()) Ans[i][j]=val[i][j]+A.val[i][j];
        return Matrix(A);
    }
    Matrix<T> operator*(Matrix<T>& A)
    {
        vector<vector<T>> Ans(A.val.size(), vector<T>(val.size(), 0));
        range2(i, A.val.size())range2(j, val.size())range2(k, val.size())Ans[i][j]=Ans[i][j]+A.val[i][k]*val[k][j];
        return Matrix(Ans);
    }
    Matrix<T> operator^(long long n) {return n>1?n&1?pow(*this**this, n/2)**this:pow(*this**this, n/2):*this;}
};
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
std::istream& operator>>(std::istream& is,  residue& A) {return is >> A.val;}
template<typename T> queue<T>& operator<<(queue<T>& q, T& x) {q.push(x); return q;}
template<typename T> queue<T>& operator>>(queue<T>& q, T& x) {x = q.front();q.pop(); return q;}

// Output:A
template<typename T> void print(const std::set<T>& S, std::ostream& os=cout, string sep = ", ")
{
    os << "{";
    for (T el:S) os << el << sep;
    os << "}\n";
}
template<typename T> void print(const std::multiset<T>& S, std::ostream& os=cout, string sep = ", ")
{
    os << "{";
    for (T el:S) os << el << sep;
    os << "}\n";
}
template<typename T> void print(const T& t, std::ostream& os=cout)
{
    os << t;
}
template<typename T> void print(const std::vector<T>& vec, std::ostream& os=cout, string sep = ", ")
{
    print("[");
    for (int i = 0; i < vec.size() - 1; i++) print(vec[i]), print(sep);
    print(vec.back());
    print("]\n");
}
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
std::ostream& operator<<(std::ostream& os, const residue a) {return os << a.val;}
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> a) {return os << a.val;}
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T1, typename T2, typename T3>
std::ostream& operator<<(ostream& os,const std::tuple<T1,T2,T3>& p){return os<<"("<<p.first<<", "<<p.second<<", "<<p.third<<")";}


template<typename T> void operator+=(std::vector<T>& vec, T el) {vec.push_back(el);}
template<typename T> vector<T> operator+(std::vector<T> A, std::vector<T> B) {for(T el:B)A+=el; return A;}
template<typename T> vector<T> operator+(std::vector<T> A, T a) {return A+=a, A;}
template<typename T> void operator+=(std::set<T>& S, T el) {S.insert(el);}
template<typename T> void operator+=(std::multiset<T>& S, T el) {S.insert(el);}
template<typename T> void operator-=(std::set<T>& S, T el) {S.erase(el);}
template<typename T> void operator-=(std::multiset<T>& S, T el) {S.erase(el);}
template<typename T>
void sort(std::vector<T> &v){sort(v.begin(), v.end());}
template<typename T1, typename T2> std::pair<T1, T2> operator+(const pair<T1, T2>& p1, const pair<T1, T2>& p2)
{return pair<T1, T2>(p1.fi+p2.fi,p1.se+p2.se);}
template<typename T1, typename T2, typename T3> std::pair<T1, T2> operator*(const pair<T1, T2>& p1, const T3 m) {return pair<T1, T2>(p1.fi*m,p1.se*m);}


long long gcd(long long x, long long y){return y?gcd(y, x % y):x;}
long long euler(long long n)//promlem at n >= (1<<62)
{
    long long ans = n;
    for(int i = 2, t = sqrt(n); i<=t; i++)
    {
        if(n % i == 0) ans = (ans)/i*(i-1);
        while (n % i == 0) n/=i;
    }
    return (n-1)?(ans)/n*(n-1):ans;
}
vpii factorization(long long n)//promlem at n >= (1<<62)
{
    vector<pair<int, int>> Ans;
    for(int i = 2, t = sqrt(n); i <= t; i++)
    {
        if(n % i == 0) Ans.push_back(pair<int, int>(i, 0));
        while(n % i == 0) n /= i, Ans.back().second++;
    }
    return (n-1)?Ans+pair<int, int>(n, 1):Ans;
}
int kek()
{
    cout << "kek" << endl;
    return 0;
}
int main()
{
    int loops = 1;
    while(loops--)
    {
        ll n, sum=0, a, m, k, b, c, d, p, r, i;
        cin >>k >> n;
        vi A(k);
        map<int, int> M;
        //map<pii, int> ans;
        multiset<pii> ans;
        set<pii> S;
        cin >> A;
        forx(i, n) if(A[i]==-1)A[i]=1;
        forx(i, n) M[A[i]]++;
        for(auto el:M) S.insert({el.se, el.fi});
        cout << "kek" << endl;
        for(auto cur =  (kek(), S.lower_bound({k/n, 0})); cur!=S.end()&&cur->fi == k/n;cur++)
        {
            cout << "kek" << endl;
            forx(k/n)ans.insert({cur->se, cur->se});
        }

        for(auto el:S) if(el.fi==n/k)S.erase(el);
        while(!S.empty())
        {
            auto mi = *S.begin(), ma = *(--S.end());
            S.erase(S.begin());
            S.erase(--S.end());
            cout<<"kek"<< endl;
            forx(i, mi.fi) ans.insert(pii(mi.se, ma.se));
            cout<<"kek"<< endl;
            //if((n/k)-mi.fi)for(int i = 0; i < (n/k)-mi.fi; i++) ans.insert(pii(ma.se, mi.se));
            cout<<"kek"<< endl;

            ma.fi-=(n/k)-mi.fi;
            if(ma.fi)S.insert(ma);
        }
        cout << "Yes"<< endl;
        for(auto el:ans) cout << el << endl;

        forx(i, n)
        {
            auto cur = ans.lower_bound(pii(A[i], -1));
            cout << *cur <<"\n";
            ans.erase(cur);
        }
    }
    return 0;
}
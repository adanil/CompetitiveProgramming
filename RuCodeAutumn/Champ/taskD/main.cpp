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
#include <unordered_map>

namespace FastIO {
    struct Reader {
    private:
        FILE* file; std::vector<char> buffer; int pos; bool was;
        void read() {
            if (!buffer.empty()) {
                buffer.resize(fread(&buffer[0], 1, (int)buffer.size(), file)); pos = 0;
            }
        }
    public:
        Reader(FILE* file_ = stdin, const int size_ = 1 << 16)
                : file(file_), buffer(size_, '\0'), pos(size_), was(true) { }
        operator bool() const { return was; }
        char getChar() {
            if (pos == (int)buffer.size()) { read(); }
            if (pos == (int)buffer.size()) { was = false; return EOF; }
            else { was = true; return buffer[pos++]; }
        }
        std::string getStr() {
            char c = ' ';
            while (std::isspace(c)) { c = getChar(); }
            std::string answ;
            while (c != EOF && !std::isspace(c)) { answ.push_back(c); c = getChar(); }
            was = !answ.empty();
            return answ;
        }
        std::string getLine() {
            char c = '\n';
            while (c == '\n') { c = getChar(); }
            std::string answ;
            while (c != '\n' && c != EOF) { answ.push_back(c); c = getChar(); }
            was = !answ.empty();
            return answ;
        }
        template<typename T> T getInt() {
            char c = '?';
            while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) { c = getChar(); }
            bool positive = true;
            if (c == '-') { positive = false; c = getChar(); }
            T answ(0);
            bool flag = false;
            while ('0' <= c && c <= '9') { flag = true; (answ *= 10) += (c - '0'); c = getChar(); }
            was = flag;
            return positive ? answ : -answ;
        }
        template<typename T> T getReal() {
            bool flag = false;
            char c = '?';
            while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) { c = getChar(); }
            bool positive = (c != '-');
            if (c == '-') { c = getChar(); }
            long long first = 0;
            while ('0' <= c && c <= '9') { flag = true; (first *= 10) += (c - '0'); c = getChar(); }
            was = flag;
            if (c != '.') { return T(positive ? first : -first); }
            c = getChar();
            long long second = 0, pow = 1;
            while ('0' <= c && c <= '9') { (second *= 10) += (c - '0'); c = getChar(); pow *= 10; }
            T answ = first + (T)second / (T)pow;
            return positive ? answ : -answ;
        }
    };

    Reader& operator>>(Reader& reader, char& c) { return c = reader.getChar(), reader; }

    Reader& operator>>(Reader& reader, std::string& s) { return s = reader.getStr(), reader; }

    template<class T> typename std::enable_if<std::is_floating_point<T>::value, Reader&>::type
    operator>>(Reader& reader, T& t) { return t = reader.getReal<T>(), reader; }

    template<class T> typename std::enable_if<std::is_integral<T>::value, Reader&>::type
    operator>>(Reader& reader, T& t) { return t = reader.getInt<T>(), reader; }

    template<class T> Reader& operator>>(Reader& reader, std::vector<T>& vec) {
        for (auto &it : vec) { reader >> it; }
        return reader;
    }

    struct Writer {
    private:
        FILE* file; std::vector<char> buffer; int pos;
        int defaultPrecision, defaultWidth; char defaultFill;
    public:
        Writer(FILE* file_ = stdout, const int size_ = 1 << 16)
                : file(file_), buffer(size_, '\0'), pos(0), defaultPrecision(6), defaultWidth(0), defaultFill(' ') { }
        ~Writer() { flush(); }
        void flush() { putChar(EOF); }
        void setprecision(int precision) { defaultPrecision = precision; }
        void setw(int width) { defaultWidth = width; }
        void setfill(char fill) { defaultFill = fill; }
        int getPrecision() const { return defaultPrecision; }
        int getWidth() const { return defaultWidth; }
        char getFill() const { return defaultFill; }
        void putChar(char c) {
            if (pos == (int)buffer.size() || c == EOF) {
                fwrite(&buffer[0], 1, pos, file); pos = 0;
            }
            if (c != EOF) { buffer[pos++] = c; }
        }
        void putStr(const std::string& s) { for (auto it : s) putChar(it); }
        template<typename T> void putInt(T value, int width = 0, char fill = ' ') {
            bool positive = !(value < 0);
            if (value < 0) { value = -value; }
            char buf[24]; int p = 0;
            do { buf[p++] = char(value % 10 + '0'); value /= 10; } while (value > 0);
            if (!positive) { buf[p++] = '-'; }
            while (p < width) buf[p++] = fill;
            while (p > 0) putChar(buf[--p]);
        }
        template<typename T> void putReal(T value, int precision = 6, int width = 0, char fill = ' ') {
            putInt((long long)value, width - precision - 1, fill);
            value = std::abs(value-(long long)value);
            if (precision == 0) { return; }
            putChar('.');
#define PRINT_PART(cnt, pow) \
                while (precision >= cnt) { \
                    value *= pow; \
                    putInt((int)value, cnt, '0'); \
                    value -= (int)value; \
                    precision -= cnt; \
                }
            PRINT_PART(6,1000000)
            PRINT_PART(3,1000)
            PRINT_PART(1,10)
#undef PRINT_PART
        }
    };

    Writer& operator<<(Writer& writer, const char c) { return writer.putChar(c), writer; }

    Writer& operator<<(Writer& writer, const std::string& s) { return writer.putStr(s), writer; }

    template<class T> typename std::enable_if<std::is_floating_point<T>::value, Writer&>::type
    operator<<(Writer& writer, const T& t) {
        writer.putReal(t, writer.getPrecision(), writer.getWidth(), writer.getFill());
        return writer;
    }

    template<class T> typename std::enable_if<std::is_integral<T>::value, Writer&>::type
    operator<<(Writer& writer, const T& t) {
        writer.putInt(t, writer.getWidth(), writer.getFill());
        return writer;
    }
}

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
    std::ios_base::sync_with_stdio(false);
    return true;
}();

int main()
{
    const int mx = 1e6;
    FastIO::Reader cin;
    FastIO::Writer cout;
    int n; cin >> n;
    static int vec[mx];
    static int tmp[mx];
    forx(i, n) cin >> vec[i];

    auto prefMex = [&](int x)
    {
        for (int i = 0; i < x; ++i) tmp[i] = vec[i];
        std::sort(tmp, tmp + x);
        int ans = 0;
        for (int i = 0; i < x; ++i)
        {
            if (ans == tmp[i]) ++ans;
            else if (tmp[i] > ans) break;
        }
        return ans;
    };
    int mex = prefMex(n);
    std::unordered_map<int, int> used;
    bool ok;
    int ansDl = n;
    int ansInd = 0;
    std::set<int> dontHave;
    //for (int u = 0; u <= 1e6 + 1; ++u) if (!used[u]) dontHave.insert(u);
    auto check = [&](int m)
    {
        int unique = 0;
        for (int i = 0; i < m; ++i)
        {
            if(vec[i] < mex && used[vec[i]] == 0) ++unique;
            ++used[vec[i]];
        }
        if(unique >= mex) ok = true, ansDl = m, ansInd = 0;
        if(ok) return;
        for (int i = 1; i <= (n - m); ++i)
        {
            int goodbye = vec[i - 1];
            int hello = vec[i + m - 1];
            --used[goodbye];
            if(goodbye < mex && used[goodbye] == 0) --unique;
            if (hello < mex && !used[hello]) ++unique;
            ++used[hello];
            if (unique >= mex) ok = true, ansDl = m, ansInd = i;
            if (ok) return;
        }
    };

    int l = n, r = 0;
    while (l - r > 1)
    {
        int mid = l + r >> 1;
        used.clear();
        ok = false;
        check(mid);
        if (ok) l = mid;
        else r = mid;
    }
    cout << (ansInd + 1) << " " << ansInd + ansDl << "\n";
    return 0;
}
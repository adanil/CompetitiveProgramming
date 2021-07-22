#include <iostream>
#include <vector>

using namespace std;
using ll = long long;










#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <numeric>
#include <iterator>
#include <math.h>
#include <assert.h>
#include <fstream>
#include <set>

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

vell ans;

void merge(vell& vec, int l, int m, int r)
{
    vell tmp(r - l);
    int it1(0), it2(0);

    while (l + it1 < m && m + it2 < r)
    {
        if (vec[l + it1] < vec[m + it2])
        {
            tmp[it1 + it2] = vec[l + it1];
            ++it1;
        }
        else
        {
            tmp[it1 + it2] = vec[m + it2];
            ans[vec[m + it2]] += (m - l - it1);
            ++it2;
        }
    }

    while (l + it1 < m)
    {
        tmp[it1 + it2] = vec[l + it1];
        ++it1;
    }

    while (m + it2 < r)
    {
        tmp[it1 + it2] = vec[m + it2];
        ++it2;
    }

    forx(i, r - l) vec[l + i] = tmp[i];
}

// [L;R)
void merge_sort(vell& vec, int l, int r)
{
    if (r - l < 2) return;
    int m = l + r >> 1;
    merge_sort(vec, l, m);
    merge_sort(vec, m, r);
    merge(vec, l, m, r);
}

namespace SegmentTreeLazy
{

    /*******************************************************************************
    *  SegmentTree<Value, Extra, Traits> - segment tree class with lazy propagation, 0-indexed
    *  Default operations: minimal value on segment and addition on segment for int64_t type
    *  Use Traits<Value,Extra> for definition of:
    *      1)  neutral element for `Value`;
    *      2)  neutral element for `Extra`;
    *      3)  how should combine `Extra` with `Value`;
    *      4)  how should combine `Value` with `Value` (children to root);
    *      5)  how should combine `Extra` with `Extra`;
    *  See examples below: TraitsMinAdd<Value, Extra>
    ******************************************************************************/

    /*******************************************************************************
    *  Available traits, implemented below
    ******************************************************************************/
    template<typename Value, typename Extra> struct TraitsMinAdd;
    template<typename Value, typename Extra> struct TraitsMaxAdd;
    template<typename Value, typename Extra> struct TraitsSumSet;

    /*******************************************************************************
    *  Traits for minimal value on segment.
    *  Get-query:    get minimal value in segment [l, r]
    *  Update-query: add const to each value in segment [l, r]
    ******************************************************************************/
    template<typename Value, typename Extra>
    struct TraitsMinAdd {
        // Definition of neutral element for `Value`:
        static Value valueNeutral() { return std::numeric_limits<Value>::max(); }
        // Definition of neutral element for `Extra`:
        static Extra extraNeutral() { return Extra(0); }
        // Definition of how should combine `Extra` with `Value`:
        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        // Definition of how should combine `Value` with `Value` (children to root):
        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::min(getValue(lt), getValue(rt));
        }
        // Definition of how should combine `Extra` with `Extra`:
        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };

    /*******************************************************************************
    *  SegmentTree, see description above
    ******************************************************************************/
    template<typename Value = int64_t, typename Extra = int64_t, typename Traits = TraitsMinAdd<Value, Extra> >
    struct SegmentTree {

        /*******************************************************************************
        *  Node class
        ******************************************************************************/
        struct Node {
            Value value;

            Extra extra;

            Node(Value value_ = Traits::valueNeutral(), Extra extra_ = Traits::extraNeutral())
                    : value(value_), extra(extra_) { }

            Value getValue(int l, int r) const { return Traits::getValue(NodeWrapper<Node>(l, r, *this)); }
        };

        /*******************************************************************************
        *  NodeWrapper class
        ******************************************************************************/
        template<typename NodeType>
        struct NodeWrapper {
            int l, r;
            NodeType node;
            NodeWrapper(int l_, int r_, NodeType node_)
                    : l(l_), r(r_), node(node_) { }
            int  left() const { return l; }
            int right() const { return r; }
            int   mid() const { return (l + r) / 2; }
            int   len() const { return r - l + 1; }
            Value& value() { return node.value; }
            Extra& extra() { return node.extra; }
            const Value& value() const { return node.value; }
            const Extra& extra() const { return node.extra; }
        };

        /*******************************************************************************
        *  SegmentTree public data: n - number of items, data - vector for nodes
        ******************************************************************************/
        int n; std::vector<Node> data;


        /*******************************************************************************
        *  Resize segment tree data to needed size
        ******************************************************************************/
        void resize(int n_) {
            n = n_;
            data.assign(2 * n - 1, Node());
        }

        /*******************************************************************************
        *  Lazy propagation from node to its children
        ******************************************************************************/
        void push(int v, int l, int r, int m) {
            if (data[v].extra != Traits::extraNeutral()) {
                Traits::push(
                        NodeWrapper<Node&>(l, m, data[v + 1]),
                        NodeWrapper<const Node&>(l, r, data[v])
                );
                Traits::push(
                        NodeWrapper<Node&>(m + 1, r, data[v + 2 * (m - l + 1)]),
                        NodeWrapper<const Node&>(l, r, data[v])
                );
                data[v].extra = Traits::extraNeutral();
            }
        }

        /*******************************************************************************
        *  Update node using children values
        ******************************************************************************/
        void pull(int v, int l, int r, int m) {
            assert(data[v].extra == Traits::extraNeutral());
            Traits::pull(
                    NodeWrapper<Node&>(l, r, data[v]),
                    NodeWrapper<const Node&>(l, m, data[v + 1]),
                    NodeWrapper<const Node&>(m + 1, r, data[v + 2 * (m - l + 1)])
            );
        }

        /*******************************************************************************
        *  Build segtree from array with given values
        ******************************************************************************/
        template<typename T>
        void build(const std::vector<T>& arr, const int v, const int tl, const int tr) {
            if (tl == tr) {
                data[v] = Node(arr[tl]);
            }
            else {
                const int tm = (tl + tr) / 2;
                build(arr, v + 1, tl, tm);
                build(arr, v + 2 * (tm - tl + 1), tm + 1, tr);
                pull(v, tl, tr, tm);
            }
        }

        template<typename T>
        void build(const std::vector<T>& arr) {
            resize((int)arr.size());
            build(arr, 0, 0, n - 1);
        }

        /*******************************************************************************
        *  Get-query on range [ql, qr]
        ******************************************************************************/
        Node get(int ql, int qr, const int v, const int tl, const int tr) {
            if (ql == tl && qr == tr) {
                return data[v];
            }
            else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                Node ret;
                if (qr <= tm) {
                    ret = get(ql, qr, v + 1, tl, tm);
                }
                else if (ql > tm) {
                    ret = get(ql, qr, v + 2 * (tm - tl + 1), tm + 1, tr);
                }
                else {
                    const auto lt = get(ql, tm, v + 1, tl, tm);
                    const auto rt = get(tm + 1, qr, v + 2 * (tm - tl + 1), tm + 1, tr);
                    Traits::pull(
                            NodeWrapper<Node&>(ql, qr, ret),
                            NodeWrapper<const Node&>(ql, tm, lt),
                            NodeWrapper<const Node&>(tm + 1, qr, rt)
                    );
                }
                pull(v, tl, tr, tm);
                return ret;
            }
        }

        Value get(const int ql, const int qr) { return get(ql, qr, 0, 0, n - 1).getValue(ql, qr); }

        /*******************************************************************************
        *  Update query on range [ql, qr] by extra
        ******************************************************************************/
        void update(const int ql, const int qr, const Extra& extra, const int v, const int tl, const int tr) {
            if (ql == tl && tr == qr) {
                Traits::push(
                        NodeWrapper<Node&>(tl, tr, data[v]),
                        NodeWrapper<Node>(ql, qr, Node(Traits::valueNeutral(), extra))
                );
            }
            else {
                int tm = (tl + tr) / 2;
                push(v, tl, tr, tm);
                if (qr <= tm) {
                    update(ql, qr, extra, v + 1, tl, tm);
                }
                else if (ql > tm) {
                    update(ql, qr, extra, v + 2 * (tm - tl + 1), tm + 1, tr);
                }
                else {
                    update(ql, tm, extra, v + 1, tl, tm);
                    update(tm + 1, qr, extra, v + 2 * (tm - tl + 1), tm + 1, tr);
                }
                pull(v, tl, tr, tm);
            }
        }

        void update(const int ql, const int qr, const Extra& extra) {
            update(ql, qr, extra, 0, 0, n - 1);
        }

    };

    /*******************************************************************************
    *  Traits for maximal value on segment.
    *  Get-query:    get maximal value in segment [l, r]
    *  Update-query: add const to each value in segment [l, r]
    ******************************************************************************/
    template<typename Value, typename Extra>
    struct TraitsMaxAdd {
        // Definition of neutral element for `Value`:
        static Value valueNeutral() { return std::numeric_limits<Value>::min(); }
        // Definition of neutral element for `Extra`:
        static Extra extraNeutral() { return Extra(0); }
        // Definition of how should combine `Extra` with `Value`:
        template<typename Node>
        static Value getValue(const Node& src) {
            return src.value() + src.extra();
        }
        // Definition of how should combine `Value` with `Value` (children to root):
        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = std::max(getValue(lt), getValue(rt));
        }
        // Definition of how should combine `Extra` with `Extra`:
        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() += src.extra();
        }
    };

    /*******************************************************************************
    *  Traits for maximal value on segment.
    *  Get-query:    sum of values on segment [l, r]
    *  Update-query: set const to each value in segment [l, r]
    ******************************************************************************/
    template<typename Value, typename Extra>
    struct TraitsSumSet {
        // Definition of neutral element for `Value`:
        static Value valueNeutral() { return Value(0); }
        // Definition of neutral element for `Extra`:
        static Extra extraNeutral() { return Extra(-1); }
        // Definition of how should combine `Extra` with `Value`:
        template<typename Node>
        static Value getValue(const Node& src) {
            return src.extra() == extraNeutral() ? src.value() : src.len() * src.extra();
        }
        // Definition of how should combine `Value` with `Value` (children to root):
        template<typename NodeRoot, typename NodeLt, typename NodeRt>
        static void pull(NodeRoot root, const NodeLt& lt, const NodeRt& rt) {
            root.value() = getValue(lt) + getValue(rt);
        }
        // Definition of how should combine `Extra` with `Extra`:
        template<typename NodeDst, typename NodeSrc>
        static void push(NodeDst dst, const NodeSrc& src) {
            dst.extra() = src.extra();
        }
    };
}

ll AnatolySolve(ll n, ll k, vell& f)
{
    using SegTree = SegmentTreeLazy::SegmentTree<ll, ll, SegmentTreeLazy::TraitsMaxAdd<ll, ll>>;
    SegTree tree;
    if (2 * k >= n)
    {
        ll ans = 0;
        for (auto x : f) ans += x;
//        cout << ans << "\n";
        return ans;
    }

    ll ans = 0;
    ll tryAns = 0;

    forx(i, 2 * k) tryAns += f[i];
    remax(ans, tryAns);
    for (int i = 1; i <= (n - 2 * k); ++i)
    {
        tryAns += f[i + 2 * k - 1];
        tryAns -= f[i - 1];
        remax(ans, tryAns);
    }

    ll dlk = 0;
    vell ksum;
    forx(i, k) dlk += f[i];
    for (int i = 1; i <= (n - k); ++i)
    {
        ksum.push_back(dlk);
        dlk += f[i + k - 1];
        dlk -= f[i - 1];
    }
    ksum.push_back(dlk);
    tree.build(ksum);
    for (int i = 0; i <= (n - k); ++i)
    {
        if (i + k + 1 <= (n - k))
        {
            int left = i + k + 1;
            int right = ksum.size() - 1;
            if (left <= right)
            {
                tryAns = ksum[i] + tree.get(left, right);
                remax(ans, tryAns);
            }
        }
    }
    return ans;
}























///fajsdkasjdkasjdkajsdkasjdkjaskd

ll solve(ll n,ll k,vector<ll> &fire){
    vector<ll>pref(n);
    for (int i = 0;i < n;i++){
        i > 0 ? pref[i] = pref[i - 1] + fire[i] : pref[i] = fire[i];
    }
    if (k >= n){
//        cout << pref[n - 1] << endl;
        return pref[n - 1];
    }
    ll max1 = 0,max2 = 0;
    ll ind1 = 0,ind2 = 0;
    for (int i = 0;i < n - (k - 1);i++){
        ll sum = 0;
        i > 0 ? sum = pref[i + k - 1] - pref[i - 1] : sum = pref[i + k - 1];
        if (sum > max1){
            max1 = sum;
            ind1 = i;
            ind2 = i + k;
        }
    }

    vector<ll>fireSec;
    for (int i = 0;i < n;i++){
        if (i >= ind1 && i < ind2)
            continue;
        fireSec.push_back(fire[i]);
    }
    vector<ll>prefSec(n - (ind2 - ind1));
    for (int i = 0;i < n - (ind2 - ind1);i++){
        i > 0 ? prefSec[i] = prefSec[i - 1] + fireSec[i] : prefSec[i] = fireSec[i];
    }

    if (k >= fireSec.size()){
        max2 = prefSec[prefSec.size() - 1];
    }
    else {
        for (int i = 0; i < n - (ind2 - ind1) - (k - 1); i++) {
            ll sum = 0;
            i > 0 ? sum = prefSec[i + k - 1] - prefSec[i - 1] : sum = prefSec[i + k - 1];
            if (sum > max2) {
                max2 = sum;
            }
        }
    }
//    cout << max1 << ' ' << max2 << endl;
//    cout << max1 + max2 << endl;
    return max1 + max2;

}

ll native(ll n,ll k,vector<ll> &fire){
    ll ans = 0;
    if (k >= n){
        for (int i = 0;i < n;i++)
            ans+= fire[i];
        return ans;
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            ll locMax1 = 0,locMax2 = 0;
            if (i == j)
                continue;
            ll kcopy = k;
            ll kcopySec = k;
            int tmp = i;
            int tmpSec = j;
            while(tmp < n && kcopy > 0){
                locMax1 += fire[tmp];
                tmp++;
                kcopy--;
            }
            while(tmpSec < n && kcopySec > 0){
                if (tmpSec >= i && tmpSec < tmp)
                    tmpSec++;
                else{
                    locMax2 += fire[tmpSec];
                    tmpSec++;
                    kcopySec--;
                }
            }
            ans = max(ans,locMax1 + locMax2);
        }
    }
    return ans;
}




int main() {
    ll n,k;
//    cin >> n >> k;
    for (ll n = 1;n < 300000;n++) {
        for (ll k = 1; k < 300000; k++) {
            srand (time(NULL));
            vector<ll> fire(n);
            for (int i = 0; i < n; i++) {
                fire[i] = rand() % 2000;
            }
            if (native(n, k, fire) != AnatolySolve(n, k, fire)) {
                cout << "ERROR: " << native(n, k, fire) << ' ' << AnatolySolve(n, k, fire) << endl;
                cout << n << ' ' << k << endl;
                for (int i = 0; i < n; i++)
                    cout << fire[i] << ' ';
                cout << endl;
                return 0;
            } else
                cout << "OK!" << endl;
        }
    }
    return 0;
}
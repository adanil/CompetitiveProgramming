#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
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
const auto ready = [)(){std::ios_base::sync_with_stdio(false);std::cin.tie(0); std::cout.tie(0);
    std::cout << std::fixed;
    return 1;}();


class node
{
public:
    int l=0, r=0, max=-1e9, min=1e9, v=0;
    node()
    {

    }
    node(int V)
    {
        v = V;
        max=v;
        min=v;
    }

};
std::vector<node> tree;
void calculate(int cur)
{
    if(cur == 0) return;
    calculate(tree.at(cur).l);
    calculate(tree.at(cur).r);
    tree.at(cur).min=min(tree.at(cur).min, tree.at(tree.at(cur).l).min);
    tree.at(cur).max=max(tree.at(cur).max, tree.at(tree.at(cur).r).max);
}
struct SegTree
{
    int n;
    vvi data;
    vi left_inds;
    SegTree(vi& vec, vector<pii>& prs) // vec with sorted pairs
    {
        n = vec.size();
        data.resize(4 * n);
        left_inds.resize(n);
        forx(i, n) left_inds.at(i) = prs.at(i).first;
        build(0, 0, n - 1, vec);
    }

    void build(int v, int l, int r, vi& vec)
    {
        if (l == r)
        {
            data.at(v).push_back(vec.at(l));
        }
        else
        {
            int m = l + r >> 1;
            build(2 * v + 1, l, m, vec);
            build(2 * v + 2, m + 1, r, vec);
            std::merge(all(data.at(2 * v + 1)), all(data.at(2 * v + 2)), std::back_inserter(data.at(v)));
        }
    }
    int get(int v, int l, int r, int ql, int qr, int l_invariant, int r_invariant)
    {
        if (l > qr || r < ql) return 0;
        else if (l == ql && r == qr)
        {
            return int(std::upper_bound(all(data.at(v)), r_invariant) - data.at(v).begin());
        }
        else
        {
            int m = l + r >> 1;
            return get(2 * v + 1, l, m, ql, std::min(qr, m), l_invariant, r_invariant) + get(2 * v + 2, m + 1, r, std::max(ql, m + 1), qr, l_invariant, r_invariant);
        }
    }

    int get(int ql, int qr)
    {
        int left = int(std::lower_bound(all(left_inds), ql) - left_inds.begin());
        int right = int(std::upper_bound(all(left_inds), qr) - left_inds.begin()) - 1;
        if (left > right) return 0;
        else return get(0, 0, n - 1, left, right, ql, qr);
    }
};
int main()
{
    try {
        ll k, l, r, Max, A, B, n, maxCall, q, count;
        cin >> n;
        tree.resize(n + 1);
        forx(i, 1, n + 1) {
            cin >> l >> r >> k;
            tree.at(i) = node(k);
            tree.at(i).l = l;
            tree.at(i).r = r;
        }
        calculate(1);
        maxCall = n;
        forx(i, 1, n + 1) {
            if (tree.at(i).min < tree.at(i).max && tree.at(i).l == 0) maxCall++;
            if (tree.at(i).min < tree.at(i).max && tree.at(i).r == 0) maxCall++;
        }
        //cout << maxCall << "\n";
        //forx(i, 1, n+1) cout << tree.at(i).min << " " << tree.at(i).max << "\n";
        std::vector<pair<int, int>> segments, segments_reverse;
        segments.reserve(n);
        forx(i, 1, n + 1) if (tree.at(i).min < tree.at(i).max) segments.push_back(pii(tree.at(i).min, tree.at(i).max));
        segments_reverse.reserve(segments.size());
        for (auto &p:segments) segments_reverse.push_back(pii(p.se, p.fi));
        sort(segments.begin(), segments.end());
        sort(segments_reverse.begin(), segments_reverse.end());
        cout << segments << segments_reverse;
        vi rights;
        for (auto p:segments) rights.push_back(p.se);
        SegTree Tree(rights, segments);
        cin >> q;
        forx(q) {
            cin >> l >> r;
            count = 0;
            count += upper_bound(all(segments_reverse), pii(l, -1e9)) - segments_reverse.begin();
            count += segments.end() - lower_bound(all(segments), pii(r, 1e9));
            count += Tree.get(l, r);
            //for(auto p: segments) if(l<=p.fi&&r>=p.se) count++;//need2optimize
            cout << maxCall - count * 2 << "\n";
        }
    }
    catch(...){

    }
    return 0;
}
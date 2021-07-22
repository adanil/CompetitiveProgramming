#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

#define MAX 200001
int lookup[MAX][20];


void buildSparseTable(vector<ll> &arr, int n)
{
    // Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {

        // Compute minimum value for all intervals with
        // size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            // For arr[2][10], we compare arr[lookup[0][7]]
            // and arr[lookup[3][10]]
            if (lookup[i][j - 1] <
                lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] =
                        lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    int j = (int)log2(R - L + 1);

    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];

    else
        return lookup[R - (1 << j) + 1][j];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin >> n >> q;
    bool haveQ = false;
    bool haveZero = false;
    vector<ll>a(n);



    int zeros = 0;
    bool ok = true;
    int first_zero = -1;
    int first_q = -1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > q) ok = false;
        if (!a[i]) ++zeros;
        if (!a[i] && first_zero == -1) first_zero = i;
        if (a[i] == q && first_q == -1) first_q = i;
    }
    if (!ok)
    {
        cout << "NO\n";
        return 0;
    }
    if (zeros == n)
    {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << q << " ";
        cout << "\n";
        return 0;
    }
    for (int i = 1; i < n; ++i) if (!a[i]) a[i] = a[i - 1];
    for (int i = n - 2; i >= 0; --i) if (!a[i]) a[i] = a[i + 1];
    if (first_q == -1 && first_zero == -1)
    {
        cout << "NO\n";
        return 0;
    }
    else if (first_q == -1 && first_zero != -1)
    {
        a[first_zero] = q;
    }
    
    
    
    
    
    
    ///-----
//    for (auto &el:a) {
//        cin >> el;
//        if (el == q){
//            haveQ = true;
//        }
//        if (el == 0)
//            haveZero = true;
//    }
//    if (!haveQ && !haveZero){
//        cout << "NO" << endl;
//        return 0;
//    }
//    for (int i = 0;i < n;i++){
//        if (a[i] == 0) {
//            if (i == 0 && !haveQ)
//                a[i] = q;
//            else if (i == 0 && haveQ)
//                a[i] = 1;
//            else
//                a[i] = a[i-1];
//        }
//        if (a[i] > q){
//            cout << "NO" << endl;
//            return 0;
//        }
//    }
    vector<pair<ll,ll>>brd(q+1,{-1,-1});
    for (int i = 0;i < n;i++){
        if (brd[a[i]].first == -1)
            brd[a[i]].first = i;
        else{
            brd[a[i]].second = i;
        }
    }

    buildSparseTable(a, n);

    for (int i = 1;i <= q;i++){
        if (brd[i].first == -1 || brd[i].second == -1)
            continue;
        if (query(brd[i].first,brd[i].second) < i){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto &el : a)
        cout << el << ' ';
    cout << endl;

    return 0;
}
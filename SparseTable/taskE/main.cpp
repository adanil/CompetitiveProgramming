#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;
using ll = long long;

auto query(int l,int r,const vector<vector<pair<int,int>>> &st,const function<pair<int,int>(pair<int,int>,pair<int,int>)> &comp){
    int len = r - l;
    int k = 0;
    while ((1u << k) < len) {
        k++;
    }
    if ((1u << k) == len)
        return st[k][l];
    else{
        k--;
        return comp(st[k][l],st[k][r - (1u << k)]);
    }


}



//KKK
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto &el : a)
        cin >> el;

    function<pair<int,int>(pair<int,int>,pair<int,int>)> mx = [&](pair<int,int> a,pair<int,int> b){return max(a,b);};

    vector<vector<pair<int,int>>>stmx(20,vector<pair<int,int>>(n));

    for (int i = 0;i < n;i++){
        stmx[0][i].first = a[i];
        stmx[0][i].second = i;
    }

    for (int k = 1;k < 20;k++){
        for (int i = 0;i + (1u << k) <= n;i++){
            stmx[k][i] = max(stmx[k - 1][i],stmx[k-1][i + (1u << (k - 1))]);
        }
    }
    ll maxsums = 0;
    ll minsums = 0;
    for (int i = 0;i < n;i++){
        ll curr = a[i];
        ll l = i,r,q = n;
        r = (l + q)/2;
        while(r >= l && r < q){
            pair<int,int> tmp = query(i,r + 1,stmx,mx);
            if ( tmp.first <= curr && tmp.second == i){
                l = r;
                r = (r + q + 1)/2;
            }
            else{
                q = r;
                r = (l + q)/2;
            }
        }

        ll rightBound = r;

        l = 0,r = i + 1,q = -1;
        l = (l + r)/2;
        while(l < r && l > q){
            pair<int,int> tmp = query(l,i + 1,stmx,mx);
            if (tmp.first > curr || tmp.second != i){
                q = l;
                l = (q + r + 1)/2;
            }
            else{
                r = l;
                l = (q + l + 1)/2;
            }
        }

        ll leftBound = l;
//        cout << "curr: " << curr << " left bound: " << leftBound << " right bound: "<< rightBound << endl ;
        ll lf = rightBound - i - 1;
        ll rg = i - leftBound;
        maxsums += lf * curr + rg * curr + lf*rg * curr + curr;
    }


    stmx.clear();


    function<pair<int,int>(pair<int,int>,pair<int,int>)> mn = [&](pair<int,int> a,pair<int,int> b){return min(a,b);};

    vector<vector<pair<int,int>>>stmn(20,vector<pair<int,int>>(n));

    for (int i = 0;i < n;i++){
        stmn[0][i].first = a[i];
        stmn[0][i].second = i;
    }

    for (int k = 1;k < 20;k++){
        for (int i = 0;i + (1u << k) <= n;i++){
            stmn[k][i] = min(stmn[k - 1][i],stmn[k-1][i + (1u << (k - 1))]);
        }
    }


    for (int i = 0;i < n;i++){
        int curr = a[i];
        ll l = i,r,q = n;
        r = (l + q)/2;
        while(r >= l && r < q){
            pair<int,int> tmp = query(i,r + 1,stmn,mn);
            if (tmp.first >= curr && tmp.second == i){
                l = r;
                r = (r + q + 1)/2;
            }
            else{
                q = r;
                r = (l + q)/2;
            }
        }

        ll rightBound = r;

        l = 0,r = i + 1,q = -1;
        l = (l + r)/2;
        while(l < r && l > q){
            pair<int,int> tmp = query(l,i + 1,stmn,mn);
            if (tmp.first < curr || tmp.second != i){
                q = l;
                l = (q + r + 1)/2;
            }
            else{
                r = l;
                l = (q + l + 1)/2;
            }
        }

        ll leftBound = l;
//        cout << "curr: " << curr << " left bound: " << leftBound << " right bound: "<< rightBound << endl ;
        ll lf = rightBound - i - 1;
        ll rg = i - leftBound;
//        if (curr == 4)
//            continue;
        minsums += lf * curr + rg * curr + lf*rg * curr + curr;
    }







    cout << maxsums - minsums << endl;
//    cout << minsums << endl;
    return 0;
}
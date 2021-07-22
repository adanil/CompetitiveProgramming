#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

//bool operator< (const tuple<ll,ll,int> a, consttuple<ll,ll,int> b) const{
//    return get<0>(a) < get<0>(b);
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll INF = -10000000000;

    vector<vector<pair<ll,int>>> st(2* 100000 + 1,vector<pair<ll,int>>(26));

    vector<vector<pair<ll,int>>> sth(2* 100000 + 1,vector<pair<ll,int>>(26));

    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<tuple<ll,ll,int>>hw,wh;
       vector<pair<ll,ll>> a(n);
       tuple<ll,ll,int> minH,minW,minMul;
       int ind = 0;
       minH = tie(INF,INF,ind);
       minW = tie(INF,INF,ind);
       minMul = tie(INF,INF,ind);
       for (int i = 0;i < n;i++){
           ll h,w;
           cin >> h >> w;
           a[i] = {h,w};
           hw.push_back({h,w,i});
           wh.push_back({w,h,i});
           if (h < get<0>(minH))
               minH = tie(h,w,i);
           if (w < get<1>(minW))
               minW = tie(h,w,i);
           if (w+h < get<0>(minMul) + get<1>(minMul))
               minMul = tie(h,w,i);

       }
       sort(hw.begin(),hw.end());
        sort(wh.begin(),wh.end());

       int i = 0;

        for (auto it = hw.begin(); it != hw.end(); it++) {
            st[i++][0] = {get<1>(*it),get<2>(*it)};
        }

        for (int j = 1; j <= 25; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);


        i = 0;

        for (auto it = wh.begin(); it != wh.end(); it++) {
            sth[i++][0] = {get<1>(*it),get<2>(*it)};
        }

        for (int j = 1; j <= 25; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                sth[i][j] = min(sth[i][j-1], sth[i + (1 << (j - 1))][j - 1]);



       for (int i = 0;i < n;i++){
           bool fl = false;
//          if (get<2>(minH) != i){
//              if ((get<0>(minH) < a[i].first && get<1>(minH) < a[i].second) ||
//                      (get<1>(minH) < a[i].first && get<0>(minH) < a[i].second)) {
//                  cout << get<2>(minH) + 1 << ' ';
//                  fl = true;
//              }
//          }
//          if (!fl && get<2>(minW) != i){
//              if ((get<0>(minW) < a[i].first && get<1>(minW) < a[i].second) ||
//                  (get<1>(minW) < a[i].first && get<0>(minW) < a[i].second)) {
//                  cout << get<2>(minW) + 1 << ' ';
//                  fl = true;
//              }
//          }
//           if (!fl && get<2>(minMul) != i){
//               if ((get<0>(minMul) < a[i].first && get<1>(minMul) < a[i].second) ||
//                   (get<1>(minMul) < a[i].first && get<0>(minMul) < a[i].second)) {
//                   cout << get<2>(minMul) + 1 << ' ';
//                   fl = true;
//               }
//           }
           if (!fl){
               int h = a[i].first;
               auto it = lower_bound(hw.begin(),hw.end(),tie(h,INF,INF));
               if (it != hw.begin()){
                   it--;
                   int ind = it - hw.begin();
                   int j = log2(ind + 1);
                   pair<ll,int> res = min(st[0][j], st[ind - (1 << j) + 1][j]);
                   if (res.second != i && res.first < a[i].second) {
                       cout << res.second + 1 << ' ';
                       fl = true;
                   }
               }

               if (!fl){
                   int h = a[i].first;
                   it = lower_bound(wh.begin(),wh.end(),tie(h,INF,INF));
                   if (it != wh.begin()){
                       it--;
                       int ind = it - wh.begin();
                       int j = log2(ind + 1);
                       pair<ll,int> res = min(sth[0][j], sth[ind - (1 << j) + 1][j]);
                       if (res.second != i && res.first < a[i].second) {
                           cout << res.second + 1 << ' ';
                           fl = true;
                       }
                   }
               }
               if (!fl)
                   cout << -1 << ' ';
           }

       }
       cout << endl;

    }
    return 0;
}
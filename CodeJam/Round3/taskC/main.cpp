#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

const ll INF = 1000000000000000000;

int main() {
    ll t;
    cin >> t;
    int tcopy = t;
    while(t--){
        ll n,d;
        cin >> n >> d;
        vector<ll>a(n);
        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
        vector<pair<ll,bool>>answers(a.size());
        vector<pair<ll,bool>>answers2(a.size());
        multiset<ll>parts(a.begin(),a.end());
        ll ans = INF;
        if (n == 1){
            ans = d - 1;
        }
        else{
            for (int i = 0;i < a.size();i++){
                ll currD = d;
                currD -= parts.count(a[i]);
                if (currD < 0) {
                    answers[i].first = 0;
                    answers[i].second = true;
                }
                else{

                    if (currD - parts.count(a[i] * 2) * 2 <= 0){
                        answers[i].first += ceil(currD/2);
                        currD = 0;
                        answers[i].second = true;
                    }
                    else{
                        answers[i].first += parts.count(a[i] * 2);
                        currD -= parts.count(a[i] * 2) * 2;
                        for (int j = 0;j < a.size();j++){
                            if (currD <= 0) {
                                answers[i].second = true;
                                break;
                            }
                            if (a[j] == a[i] || a[j] == 2*a[i])
                                continue;
                            if (a[j] > a[i]){
                                if (currD - a[j]/(2*a[i]) * 2 <= 0){
                                    answers[i].first += currD/2;
                                    currD = 0;
                                    answers[i].second = true;
                                }
                                else{
                                    answers[i].first += a[j]/(2*a[i]);
                                    currD -= a[j]/(2*a[i]) * 2;
                                }
                            }
                        }
                        for (int j = 0;j < a.size();j++){
                            if (currD <= 0) {
                                answers[i].second = true;
                                break;
                            }
                            if (a[j] == a[i] || a[j] == 2*a[i])
                                continue;
                            if (a[j] > a[i]){
                                if ( a[j] % (2*a[i]) > 0){
                                    answers[i].first += 1;
                                    currD -= 1;
                                }
                            }
                        }
                    }


                }
            }
            for (int i = 0;i < a.size();i++) {
                if (answers[i].second)
                    ans = min(ans, answers[i].first);
            }


            ///----------------------------

            for (int i = 0;i < a.size();i++){
                ll copyA = a[i];
                if (a[i] != 1)
                    a[i] /= 2;
                ll currD = d;
                currD -= parts.count(a[i]);
                if (currD < 0) {
                    answers2[i].first = 0;
                    answers2[i].second = true;
                }
                else{

                    if (currD - parts.count(a[i] * 2) * 2 <= 0){
                        answers2[i].first += ceil(currD/2);
                        currD = 0;
                        answers[i].second = true;
                    }
                    else{
                        answers2[i].first += parts.count(a[i] * 2);
                        currD -= parts.count(a[i] * 2) * 2;
                        for (int j = 0;j < a.size();j++){
                            if (currD <= 0) {
                                answers2[i].second = true;
                                break;
                            }
                            if (a[j] == a[i] || a[j] == 2*a[i])
                                continue;
                            if (a[j] > a[i]){
                                if (currD - a[j]/(2*a[i]) * 2 <= 0){
                                    answers2[i].first += currD/2;
                                    currD = 0;
                                    answers2[i].second = true;
                                }
                                else{
                                    answers2[i].first += a[j]/(2*a[i]);
                                    currD -= a[j]/(2*a[i]) * 2;
                                }
                            }
                        }
                        for (int j = 0;j < a.size();j++){
                            if (currD <= 0) {
                                answers2[i].second = true;
                                break;
                            }
                            if (a[j] == a[i] || a[j] == 2*a[i])
                                continue;
                            if (a[j] > a[i]){
                                if ( a[j] % (2*a[i]) > 0){
                                    answers2[i].first += 1;
                                    currD -= 1;
                                }
                            }
                        }
                    }


                }
                a[i] = copyA;
            }

            for (int i = 0;i < a.size();i++) {
                if (answers2[i].second)
                    ans = min(ans, answers2[i].first);
            }




        }
        if (ans == INF)
            ans = d - 1;
        cout <<"Case #" << tcopy - t << ": " << ans << endl;

    }
    return 0;
}
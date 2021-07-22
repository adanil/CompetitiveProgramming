#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

void showQueue(queue<ll>q){
//    cout << q.size() << endl;
    cout << "queue: ";
    int sz = q.size();
    for(int i = 0;i < sz;i++) {
        cout << q.front() << ' ';
        q.pop();
//        cout << i << endl;
    }
    cout << endl;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>p(n);
    queue<ll>q;
    for (int i = 0;i < n;i++) {
        cin >> p[i];
        q.push(p[i]);
    }
    ll mx = *max_element(p.begin(),p.end());
//    if (k >= n){
//        cout << *max_element(p.begin(),p.end()) << endl;
//    }
//    else{
        ll curr;
        ll opp;
        curr = q.front();
        q.pop();
        opp = q.front();
        q.pop();
        if (curr > opp) {
            q.push(opp);
        }
        else{
            q.push(curr);
            curr = opp;
        }
        for (ll i = 0;i < n;i++){
            bool fl = true;
//            showQueue(q);
            if (curr == mx){
                cout << curr << endl;
                return 0;
            }
            for (ll j = 0;j < k - 1;j++){
                opp = q.front();
                q.pop();
                if (curr > opp) {
                    q.push(opp);
                }
                else{
                    fl = false;
                    q.push(curr);
                    curr = opp;
                    break;
                }
            }
            if (fl) {
                cout << curr << endl;
                return 0;
            }
        }
//    }
    return 0;
}
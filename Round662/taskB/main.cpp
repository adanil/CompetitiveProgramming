#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> mp(100001,0);
    set<int>fr,tw;
    set<int>tg;
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        mp[el]++;
        if (mp[el] == 4) {
            fr.insert(el);
            tg.insert(el);
        }
        if (mp[el] == 2) {
            tw.insert(el);
            tg.insert(el);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c >> el;
        if (c == '+') {
            mp[el]++;
            if (mp[el] == 4) {
                fr.insert(el);
                tg.insert(el);
            }
            if (mp[el] == 2) {
                tw.insert(el);
                tg.insert(el);
            }
        }
        else {
            if (mp[el] == 4) {
                fr.erase(fr.find(el));
            }
            if (mp[el] == 2) {
                tw.erase(tw.find(el));
                tg.erase(tg.find(el));
            }
            mp[el]--;
        }



        if (fr.size() >= 1){
            if (fr.size() >= 2)
                cout << "YES" << endl;
            else if (tg.size() >= 3)
                cout << "YES" << endl;
            else if (fr.size() == 1 && tw.size() == 2){
                ll a1 = mp[*tg.begin()];
                ll a2 = mp[*(++tg.begin())];
                if (a1 + a2 >= 8 && ((a1 >= 6 && a2 >= 2) || (a2 >= 6 && a1 >= 2)))
                    cout << "YES" << endl;
                else if (a1 >= 8 || a2 >= 8)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (fr.size() == 1) {
                if (mp[*fr.begin()] >= 8)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }


        } else
            cout << "NO" << endl;

//        if (tg.size() >= 3 && fr.size() >= 1){
//            cout << "YES" << endl;
//        }
//        else if (tg.size() == 2){
//            if (fr.size() == 2)
//                cout << "YES" << endl;
//            else {
//                ll sum = 0;
//                ll a1, a2;
//                a1 = mp[*tg.begin()];
//                a2 = mp[*(++tg.begin())];
//                sum = a1 + a2;
//                if (sum >= 8 && (a1 >= 6 || a2 >= 6))
//                    cout << "YES" << '\n';
//                else
//                    cout << "NO" << '\n';
//            }
//
//        } else
//            cout << "NO" << endl;



//        if ((fr.size() >= 1 && tw.size() >= 2 && tg.size() >= 3) || fr.size() >= 2){
//            cout << "YES" << '\n';
//        }
//        else if (tg.size() == 2){
//            ll sum = 0;
//            ll a1,a2;
//            a1 = mp[*tg.begin()];
//            a2 = mp[*(++tg.begin())];
//            sum = a1 + a2;
//            if (sum >= 8 && (a1 >=6 || a2 >= 6) )
//                cout << "YES" << '\n';
//            else
//                cout << "NO" << '\n';
//
//        }
//        else if (tg.size() == 1 && mp[*tg.begin()] == 8)
//            cout << "YES" << endl;
//        else
//            cout << "NO" << '\n';
    }
    cout.flush();
    return 0;
}
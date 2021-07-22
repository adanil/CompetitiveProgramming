//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <set>
//
//using namespace std;
//using ll = long long;
//
//
//ll gcd (ll a, ll b) {
//    while (b) {
//        a %= b;
//        swap (a, b);
//    }
//    return a;
//}
//
//struct fun{
//    ll vote;
//    ll enj;
//    ll id;
//};
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    ll t;
//    cin >> t;
//    while(t--){
//        ll n;
//        cin >> n;
//        vector<fun> vf(n);
//        ll votes = 0;
//        for (int i = 0;i < n;i++){
//            cin >> vf[i].enj >> vf[i].vote;
//            vf[i].id = i + 1;
//            votes += vf[i].vote;
//        }
//
//        sort(vf.begin(),vf.end(),[](fun a,fun b){
//            return a.enj > b.enj;
//        });
//
//        double answer = 0;
//        ll numerator = 0;
//        ll denominator = 0;
//        for (int i = 0;i < n;i++) {
//            answer += (double) vf[i].enj * ((double) vf[i].vote) / ((double) votes);
//            numerator += vf[i].enj * ( vf[i].vote);
//        }
//        denominator = votes;
//        ll count = 0;
//        vector<ll>myVote;
//        ll l = 0;
//        ll r = n;
//        while(l <= r){
//            ll i = (l + r)/2;
//            double mx = 0;
//            ll k = i;
//            vector<ll>currVotes(i);
//            ll currNumerator = 0;
//            ll currDenominator = votes + i;
//            for (int j = 0;j < n;j++){
//                if (k > 0){
//                    currVotes[i - k] = vf[j].id;
//                    mx += (double)vf[j].enj * ((double)vf[j].vote + 1)/((double)votes + i);
//                    currNumerator += vf[j].enj * (vf[j].vote + 1);
//                    k--;
//                }
//                else {
//                    mx += (double) vf[j].enj * ((double) vf[j].vote) / ((double) votes + i);
//                    currNumerator += vf[j].enj * (vf[j].vote);
//                }
//            }
//            if (mx > answer) {
//                answer = mx;
//                count = i;
//                myVote = currVotes;
//                numerator = currNumerator;
//                denominator = currDenominator;
//                l = i + 1;
//            }
//            else{
//                r = i - 1;
//            }
//        }
//        ll del = gcd(numerator,denominator);
//        if (del == 0)
//            del = 1;
//        cout << numerator/del << '/' << denominator/del << endl;
//        cout << count << endl;
//        for (auto el : myVote)
//            cout << el << ' ';
//        cout << endl;
//    }
//    return 0;
//}









#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;


ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}

struct fun{
    ll vote;
    ll enj;
    ll id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<fun> vf(n);
        ll votes = 0;
        for (int i = 0;i < n;i++){
            cin >> vf[i].enj >> vf[i].vote;
            vf[i].id = i + 1;
            votes += vf[i].vote;
        }

        sort(vf.begin(),vf.end(),[](fun a,fun b){
            return a.enj > b.enj;
        });

        double answer = 0;
        ll count = 0;
        vector<ll>myVote;
        ll numerator = 0;
        ll denominator = 0;

        for (int i = 0;i < n;i++){
            answer += (double)vf[i].enj * ((double)vf[i].vote)/((double)votes);
            numerator += vf[i].enj * (vf[i].vote);
        }
        denominator = votes;
        ll startNumerator = numerator;
//        cout << "answer: " << answer << " sec: " << (double)numerator/(double)denominator << endl;

        for (int i = 1;i < n;i++){
            double mx = 0;
            ll k = i;
            vector<ll>currVotes(i);
            ll currNumerator = startNumerator;
            ll currDenominator = votes + i;
            for (int j = 0;j < k;j++){
                currNumerator += vf[j].enj;
            }
            mx = (double)currNumerator/(double)currDenominator;
//            for (int j = 0;j < n;j++){
//                if (k > 0){
//                    currVotes[i - k] = vf[j].id;
//                    mx += (double)vf[j].enj * ((double)vf[j].vote + 1)/((double)votes + i);
//                    currNumerator += vf[j].enj * (vf[j].vote + 1);
//                    k--;
//                }
//                else {
//                    mx += (double) vf[j].enj * ((double) vf[j].vote) / ((double) votes + i);
//                    currNumerator += vf[j].enj * (vf[j].vote);
//                }
//            }
            if (mx > answer) {
                answer = mx;
                count = i;
                myVote.clear();
                for (int j = 0;j < i;j++)
                    myVote.push_back(vf[j].id);
                numerator = currNumerator;
                denominator = currDenominator;
            }
            else{
                break;
            }
        }
        ll del = gcd(numerator,denominator);
        cout << numerator/del << '/' << denominator/del << endl;
        cout << count << endl;
        for (auto el : myVote)
            cout << el << ' ';
        cout << endl;
    }
    return 0;
}
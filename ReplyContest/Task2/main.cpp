#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

using ll = unsigned int;

int main() {
    ofstream fout;
    ifstream fin;
    string filename = "/Users/daniilavtusko/Downloads/input-server-cce9.txt";
    fout.open("/Users/daniilavtusko/Desktop/Coding/CompetitiveProgramming/ReplyContest/Task2/ans.txt");
    fin.open(filename);
    ll t;
    fin >> t;
    for (ll i = 0;i < t;i++){
        ll n,p,start = 0,end = 0;
        fin >> n >> p;
        ll ans = n + 1;
        vector<ll> servs(n);
        for (ll j = 0;j < n;j++){
            fin >> servs[j];
        }

        vector<vector<ll>> dp(n,vector<ll>(n,0));
        for (ll j = 0;j < n;j++) {
            dp[j][0] = servs[j];
        }
        for (ll j = 0;j < n;j++){
            for (ll k = j+1;k < n;k++){
                if (dp[j][k-1 - j ] < p)
                    dp[j][k-j] = dp[j][k-1 - j] + servs[k];
            }
        }

        for (ll j = 0;j < n;j++){
            ll k = 0;
            while(dp[j][k] != 0 && k < n){
                if (dp[j][k] >= p){
                    if (dp[j][k] - p < ans - p){
                        ans = dp[j][k];
                        start = j;
                        end = k;
                    }
                }
                k++;
            }
        }

//        if (i == 0) {
//            for (ll j = 0; j < n; j++) {
//                for (ll k = 0; k < n; k++)
//                    cout << dp[j][k] << ' ';
//                cout << endl;
//            }
//        }

        cout << start << ' ' << start + end << endl;
        fout << "Case #" << i+1 << ": " << start << " " << start + end  << endl;


    }


    return 0;
}
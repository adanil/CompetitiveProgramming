#include <iostream>

using namespace std;

using ll = long long;
int main() {
    int t;
    cin >> t;
    for (int i = 0;i < t;i++){
        ll n,k;
        cin >> n >> k;
        ll ind1 = n-1,ind2 = n - 2;
        ll sum = 1;
        ll pl = 1;
        while (sum <= k){
            sum += pl;
            pl++;
        }
        ind1 = pl - 1;
        if (sum == k){
            ind2 = 0;
        }
        else{

        }
        ind2 = k - (sum - (pl - 1));
        string ans(n,'a');
        ans[n - ind1 - 1] = 'b';
        ans[n - ind2 - 1] = 'b';
        cout << ans << endl;


    }
    return 0;
}
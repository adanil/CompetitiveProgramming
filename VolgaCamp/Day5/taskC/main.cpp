#include <iostream>
#include <vector>


using namespace std;
using ll = long long;


int gcd (int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


ll n = 100000;
vector<bool>sieve(n,true);

void eratosphen(){
    sieve[1] = true;
    for (ll i = 2;i * i <= n;i++){
        if (sieve[i]) {
            for (ll j = i * i;j <= n;j += i)
                sieve[j] = false;
        }
    }
}


int main() {
    eratosphen();
//    cout<<"hi" << endl;
    int k;
    cin >> k;
    while(k--) {
        ll m;
        cin >> m;
        int x,y;
        ll p,q;
        for (int i = 2;i < sieve.size();i++){
            if (sieve[i] && m % i == 0){
                p = i;
                q = m/i;
            }
        }
        gcd(p,q,x,y);
        ll ans1;
        if (x > 0){
            ans1 = p * x;
        }
        else{
            ans1 = q * y;
        }
        cout << 0 << ' ' << 1 << ' ' << ans1 << ' ' << m - ans1 + 1 <<  endl;
    }
    return 0;
}
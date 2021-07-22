#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;


    vector<ll> primes;
    vector<ll>notPrime;

    vector<ll> prime (n+1, 1);
    prime[0] = prime[1] = 0;
    for (int i=2; i <= n; ++i)
        for (int j=i+i; j<=n; j+=i)
            prime[j] = i;

    for (int i = 2;i < n+1;i++){
        if (prime[i] == 1)
            primes.push_back(i);
        else
            notPrime.push_back(prime[i]);
    }




    sort(notPrime.begin(),notPrime.end());

    vector<ll>ans(n - 1);



    for (int i = 0;i < primes.size();i++)
        ans[i] = 1;
    for (int i = primes.size();i < n - 1;i++)
        ans[i] = notPrime[i - primes.size()];

    for (auto el: ans)
        cout << el << ' ';
    cout << endl;


    return 0;
}
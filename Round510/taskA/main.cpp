#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long m;
    cin >> m;
    vector<long long>a(n);
    long long sum = 0;
    long long kmin = 0;
    long long kmax = 0;
    long long maxOnLv = 0;
    for (long long i = 0;i < n;i++){
        cin >> a[i];
        maxOnLv = max(a[i],maxOnLv);
        sum += a[i];
    }
    kmax = maxOnLv + m;
    m -= maxOnLv * (n) - sum;
    kmin = maxOnLv;
    if (m > 0)
        kmin += m%n == 0 ? m/n : m/n + 1;

    cout << kmin << ' ' << kmax << endl;
    return 0;
}
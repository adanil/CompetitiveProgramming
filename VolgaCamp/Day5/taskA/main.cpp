#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;


ll binpow(ll x, ll n) {
    if (n == 0) return 1;
    long long u = binpow(x, n / 2);
    u = u * u;
    if (n % 2 == 1)
        u = u * x;
    return u;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m;
    cin >> m;
//    for (ll m = 1;m < 10000000;m++) {

        map<ll, vector<ll>> factors;
        factors[1] = {};
        vector<ll> poller(m + 1, -1);


        ll sigma1 = 0, sigma0 = 0;
        ll phi = 0;
        ll d = 0;
        ll mu = 0;


        for (ll i = 2; i <= m; i++) {
            ll k = 2;
            while (i % k != 0) {
                k++;
            }
            if (k == i)
                factors[i] = {i};
            else {
                factors[i].push_back(k);
                poller[i] = i / k;
            }
        }

        for (ll n = 1; n <= m; n++) {
            ll phiTmp = 1;
            ll dTmp = n;
            ll muTmp = 0;
            if (n == 1)
                dTmp = 0;
            map<ll, ll> result;
            ll poll = n;
            while (poll != -1) {
                for (ll i = 0; i < factors[poll].size(); i++)
                    result[factors[poll][i]]++;
                poll = poller[poll];
            }


            ll tmpSigma1 = 1, tmpSigma0 = 1;
            bool haveSq = false;
            bool factorsCnt = 0;
            for (auto it = result.begin(); it != result.end(); it++) {
                dTmp = min(dTmp, (ll) it->first);
                tmpSigma0 *= (it->second + 1);
                tmpSigma1 *= (binpow(it->first, it->second + 1) - 1) / (it->first - 1);
                if (it->second == 2)
                    haveSq = true;
                factorsCnt += it->second;

                phiTmp *= (binpow(it->first, it->second) - binpow(it->first, it->second - 1));
            }
            if (haveSq)
                muTmp = 0;
            else if (factorsCnt % 2 != 0)
                muTmp = -1;
            else
                muTmp = 1;
            d += dTmp;
            sigma1 += tmpSigma1;
            sigma0 += tmpSigma0;
            mu += muTmp;

            phi += phiTmp;
        }


//        ll dfirst = d, sigma0first = sigma0, sigma1first = sigma1, phiFirst = phi, mufirst = mu;
//
//        sigma1 = 0, sigma0 = 0;
//        phi = 0;
//        d = 0;
//        mu = 0;
//
//        for (ll nc = 1; nc <= m; nc++) {
//            ll phiTmp = nc;
//            ll dTmp = nc;
//            ll muTmp = 0;
//            if (nc == 1)
//                dTmp = 0;
//            map<ll, ll> result;
//            ll n = nc;
//            for (ll i = 2; i * i <= n; i++) {
//                if (n % i == 0)
//                    phiTmp -= phiTmp / i;
//                while (n % i == 0) {
//                    result[i]++;
//                    n /= i;
//                }
//            }
//            if (n > 1) {
//                result[n]++;
//                phiTmp -= phiTmp / n;
//            }
//
//            phi += phiTmp;
//
//            ll tmpSigma1 = 1, tmpSigma0 = 1;
//            bool haveSq = false;
//            bool factorsCnt = 0;
//            for (auto it = result.begin(); it != result.end(); it++) {
//                dTmp = min(dTmp, (ll) it->first);
//                tmpSigma0 *= (it->second + 1);
//                tmpSigma1 *= (binpow(it->first, it->second + 1) - 1) / (it->first - 1);
//                if (it->second == 2)
//                    haveSq = true;
//                factorsCnt += it->second;
//            }
//            if (haveSq)
//                muTmp = 0;
//            else if (factorsCnt % 2 != 0)
//                muTmp = -1;
//            else
//                muTmp = 1;
//            d += dTmp;
//            sigma1 += tmpSigma1;
//            sigma0 += tmpSigma0;
//            mu += muTmp;
//
//        }
//
//        if (d != dfirst || sigma0 != sigma0first || sigma1 != sigma1first || phi != phiFirst || mu != mufirst) {
//            cout << "ERROR!" << endl;
//            cout << d << ' ' << sigma0 << ' ' << sigma1 << ' ' << phi << ' ' << mu << endl;
//            cout << dfirst << ' ' << sigma0first << ' ' << sigma1first << ' ' << phiFirst << ' ' << mufirst << endl;
//        } else
//            cout << "OK!" << endl;


    cout << d << ' ' << sigma0 << ' ' << sigma1 << ' ' << phi << ' ' << mu << endl;
//    }
    return 0;
}
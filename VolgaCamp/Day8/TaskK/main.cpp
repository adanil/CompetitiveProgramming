#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("ultraprime.in");
    ofstream fout("ultraprime.out");
    int n = 3200;
    vector<char> prime (n+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i*i<=n; ++i) {
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    }
    set<int>primes;
    for (int i = 2;i <=n;i++) {
        if (prime[i])
            primes.insert(i);
    }


    auto it = primes.begin();
    while(it != primes.end()){
        auto s = to_string(*it);
        bool br = false;
        for (int i = 0;i < s.size();i++){
            for (int j = s.size() - 1;j >= 0;j--){
                string sb;
                for (int k = i;k <=j;k++){
                    sb.push_back(s[k]);
                }
//                if (*it == 907){
//                    cout << "it: "<< *it << ' '  <<  sb << endl;
//                }
                if (!sb.empty() && !prime[stoi(sb)]) {
//                    cout << *it << endl;
                    it = primes.erase(it);
                    br = true;
                    break;
                }
            }
            if (br)
                break;
        }
        if (!br)
            it++;
    }
    vector<int>vc;
    for (auto it = primes.begin();it != primes.end();it++){
        vc.push_back(*it);
//        cout << *it << endl;
    }
    int m;
    fin >> m;
    m--;
    if (m >= vc.size())
        fout << -1 << endl;
    else
        fout << vc[m] << endl;







    return 0;
}
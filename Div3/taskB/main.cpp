#include <iostream>
#include <string>

using namespace std;
using ll = long long;


int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,a,b;
        cin >> n >> a >> b;
        string ans;
        ll last = -1;
        bool needNew = true;
        int startN = n;
        int uniq = 0;
        while(n > 0){
            if (needNew){
                if (last == 26)
                    last = 0;
                else
                    last++;
                ans.push_back((char)last + 97);
                uniq = ans.size() % a;
                n--;
            }
            else{
                ans.push_back((char)last + 97);
                n--;
                if (ans.size() % a == 0)
                    needNew = true;
            }
            if (startN - n < b)
                needNew = true;
            else{
                if (uniq >= b){
                    needNew = false;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
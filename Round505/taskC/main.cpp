#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    if (s.size() == 1){
        cout << 1 << endl;
        return 0;
    }
    char frst = s[0];
    char last = s[s.size() - 1];
    ll ans = 0;
    int currStart = 0;
    for (int i = 0;i < s.size() - 1;i++){
        if (s[i] == s[i + 1]){
            if (frst != last){
                string s1 = s.substr(currStart,i - currStart + 1);
                string s2 = s.substr(i+1,s.size() - i);
//                cout << s1 << ' ' << s2 << endl;
                reverse(s1.begin(),s1.end());
                reverse (s2.begin(),s2.end());
                s = s1 + s2;
                frst = s[0];
                last = s[s.size()-1];
            }
            else
                currStart = i + 1;
        }
    }
//    cout << s << endl;
    ll curl = 1;
    char prev = s[0];
    for (int i = 1;i < s.size();i++){
        if (s[i] != prev){
            curl++;
            prev = s[i];
        }
        else{
            ans = max(ans,curl);
            curl = 1;
        }
    }
    ans = max(ans,curl);
    cout << ans << endl;
    return 0;
}
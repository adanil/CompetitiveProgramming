#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;

    char prev = -1;

    for (int i = 1;i < s.size() - 1;i++){
        if (s[i] == s[i + 1] && s[i] == s[i - 1]){
            if (s[i] == 'z')
                s[i] = 'a';
            else
                s[i] = s[i] + 1;
        }
    }

    for (int i = 0;i < s.size() - 1;i++){
        if (s[i] == s[i + 1]){
            char c = s[i];
            while (c == s[i + 1] || c == prev){
                if (c == 'z')
                    c = 'a';
                else
                    c++;
            }
            s[i] = c;
        }
        prev = s[i];
    }
    cout << s << endl;


    return 0;
}
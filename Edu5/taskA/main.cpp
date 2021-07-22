#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    cin >> a >> b;

    vector<char>as,bs;
    bool fl = false;
    for (int i = 0;i < a.size();i++)
        if(!fl && a[i] == '0')
            continue;
        else if (!fl && a[i] != '0') {
            fl = true;
            as.push_back(a[i]);
        }
        else if (fl)
            as.push_back(a[i]);

    fl = false;
    for (int i = 0;i < b.size();i++)
        if(!fl && b[i] == '0')
            continue;
        else if (!fl && b[i] != '0') {
            fl = true;
            bs.push_back(b[i]);
        }
        else if (fl)
            bs.push_back(b[i]);


    if (as.size() > bs.size())
        cout << ">" << endl;
    else if (bs.size() > as.size())
        cout << "<" << endl;
    else{
        for (int i = 0;i < as.size();i++) {
            if (as[i] > bs[i]) {
                cout << '>' << endl;
                return 0;
            }
            else if (bs[i] > as[i]){
                cout << "<" << endl;
                return 0;
            }
        }
        cout << "=" << endl;

    }
    return 0;
}
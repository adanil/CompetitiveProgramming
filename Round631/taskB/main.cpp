#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int>a(n,0);
        vector<bool>left(n,false);
        vector<bool>right(n,false);


        for (int i = 0;i < n;i++)
            cin >> a[i];

        int mx = 0;
        set<int>ls;
        for (int i = 0;i < n;i++){
            if (ls.find(a[i]) != ls.end())
                break;
            ls.insert(a[i]);
            mx  = max(mx,a[i]);
            if (ls.size() == mx)
                left[mx-1] = true;
        }

        mx = 0;
        set<int>rs;
        for (int i = n-1;i >=0;i--){
            if (rs.find(a[i]) != rs.end())
                break;
            rs.insert(a[i]);
            mx  = max(mx,a[i]);
            if (rs.size() == mx)
                right[mx-1] = true;
        }

        int ans = 0;
        for (int i = 0;i < n-1;i++){
            if (left[i] && right[n-2-i])
                ans++;
        }
        cout << ans << endl;

        for (int i = 0;i < n-1;i++){
            if (left[i] && right[n-2-i])
                cout << i + 1 << ' ' << n-1-i << endl;
        }


    }
    return 0;
}
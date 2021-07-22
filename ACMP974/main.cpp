#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
long long mex(vector<long long> a) {
    set<long long > b(a.begin(), a.end());
    for (int i=0; ; ++i)
        if (!b.count(i))
            return i;
}
int main() {
    while (true){
        long long a,b,c;
        cin >> a >> b >> c;
        vector<long long> d(3);
        if ( a == 0 && b == 0 && c == 0)
            return 0;
        d[0] = a;
        d[1] = b;
        d[2] = c;
        sort(d.begin(),d.end());
        if (mex(d)== 0)
            cout << "Alice wins the game." << endl;
        else
            cout << "Bob wins the game." << endl;

    }
    return 0;
}
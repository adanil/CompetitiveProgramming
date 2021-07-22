#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a,ta,b,tb;
    cin >> a >> ta;
    cin >> b >> tb;
    char c;
    int starth,startm;
    cin >> starth >> c >> startm;
    int ans = 0;
    int startTime = starth * 60 + startm;
    int endTime = startTime + ta;
    for (int i = 300;i < 24*60;i += b){
        int startB = i,endB = startB + tb;
        if (endB <= startTime || startB >= endTime)
            continue;
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}
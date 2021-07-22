#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

using ll = long long;

bool query(pair<int,int> from,pair<int,int> to){
    cout << "? " << from.first << ' ' << from.second << ' ' << to.first << ' ' << to.second << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return ans == "YES" ? true : false;
}

int dist(pair<ll,ll>from,pair<ll,ll>to){
    return abs(from.first - to.first) + abs(from.second - to.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string ans;
    pair<int,int>r = {1,2};
    pair<int,int>d = {2,1};
    pair<int,int> curr = {1,1};
    pair<int,int>to = {n,n};

    vector<pair<int,int>>pathFirst;
    bool fl = false;
    while(!fl) {
        if (dist(r, to) < n - 1) {
            fl = true;
            break;
        }
        if (r.second <= n) {

            if (query(r, to)) {
                ans += "R";
                pathFirst.push_back(r);
                r.second += 1;
                d.second += 1;
                curr.second += 1;
            } else {
                if (dist(d, to) < n - 1) {
                    fl = true;
                    break;
                }
                ans += "D";
                pathFirst.push_back(d);
                r.first += 1;
                d.first += 1;
                curr.first += 1;

            }
        }
        else{
            if (dist(d, to) < n - 1) {
                fl = true;
                break;
            }
            ans += "D";
            pathFirst.push_back(d);
            r.first += 1;
            d.first += 1;
            curr.first += 1;
        }
    }

    vector<pair<int,int>>pathSecond;
    int currInd = pathFirst.size() - 2;
    to = pathFirst[currInd];
    string ansSec;
    pair<int,int>l = {n,n-1};
    pair<int,int>u = {n-1,n};
    pair<int,int> currSecond = {n,n};
    while(dist(currSecond,pathFirst[pathFirst.size() - 1]) > 1){
        if (u.first > 0) {
            if (query(to, u)) {
                ansSec += "U";
                pathSecond.push_back(u);
                l.first -= 1;
                u.first -= 1;
                currSecond.first -= 1;
            } else {
                ansSec += "L";
                pathSecond.push_back(l);
                l.second -= 1;
                u.second -= 1;
                currSecond.second -= 1;
            }
        }
        else{
            ansSec += "L";
            pathSecond.push_back(l);
            l.second -= 1;
            u.second -= 1;
            currSecond.second -= 1;
        }
        currInd--;
        to = pathFirst[currInd];
    }
    if (n > 2) {
        if (pathSecond[pathSecond.size() - 1].first == pathFirst[pathFirst.size() - 1].first)
            ans += 'R';
        else
            ans += 'D';
    }
    if (n == 2){
        if (n == pathFirst[pathFirst.size() - 1].first)
            ans += 'R';
        else
            ans += 'D';
    }
//    cout << ans << " " << ansSec << endl;
    for (int i = ansSec.size()-1;i >= 0;i--)
        if (ansSec[i] == 'U')
            ans += 'D';
        else
            ans += 'R';
    cout <<"! " << ans << endl;
    fflush(stdout);
    return 0;
}
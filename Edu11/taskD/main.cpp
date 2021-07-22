#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using ll = long long;
using namespace std;
const double EPS = 0.001;

struct Point{
    double x,y;
};

bool operator< (Point a,Point b){
    return make_pair(a.x,a.y) < make_pair(b.x,b.y);
}

struct Line{
    Point a,b;
};

Point intersecLines(Line f,Line s){
    double xinter,yinter;
    double k1 = (f.b.y - f.a.y)/(f.b.x - f.a.x);
    if (f.b.x - f.a.x == 0) {
        k1 = 0;
        xinter = f.a.x;
    }
    double k2 = (s.b.y - s.a.y)/(s.b.x - s.a.x);
    if (s.b.x - s.a.x == 0) {
        k2 = 0;
        xinter = s.b.x;
    }
    double y01 = f.a.y - k1*f.a.x;
    double y02 = s.a.y - k2*s.a.x;

    if (f.b.x - f.a.x == 0) {
        yinter = k2 * xinter + y02;
        return Point{xinter,yinter};
    }
    if (s.b.x - s.a.x == 0){
        yinter = k1 * xinter + y01;
        return Point{xinter,yinter};
    }
    xinter = (y02 - y01)/(k1 - k2);
    yinter = k1 * xinter + y01;

    return Point{xinter,yinter};
}

bool isMid(Point p,Line l){
    return (fabs(sqrt(pow(l.a.x - p.x,2) + pow(l.a.y - p.y,2)) - sqrt(pow(l.b.x - p.x,2) + pow(l.b.y - p.y,2))) < EPS);
}

Point calcMid(Line l){
    double xMid = (max(l.b.x,l.a.x) + min(l.b.x,l.a.x))/2.0;
    double yMid = (max(l.b.y,l.a.y) + min(l.b.y,l.a.y))/2.0;
    if (l.a.x == l.b.x)
        xMid = l.a.x;
    if (l.a.y == l.b.y)
        yMid = l.a.y;
    return Point{xMid,yMid};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Point>p(n);
    for (int i = 0;i < n;i++){
        cin >> p[i].x >> p[i].y;
    }
    vector<Line>ls;
    for (int i = 0;i < n;i++){
        for (int j = i + 1;j < n;j++){
            ls.push_back(Line{p[i],p[j]});
        }
    }


    map<Point,ll> centers;
    for (int i = 0;i < ls.size();i++){
        centers[calcMid(ls[i])]++;
    }

    ll ans = 0;

    for (auto it = centers.begin();it != centers.end();it++){
        ll cnt = it->second;
        ans += (cnt*(cnt-1))/2;
    }
    cout << ans << endl;


    //NATIVE

//    ll ans = 0;
//    for (int i = 0;i < ls.size();i++){
//        for (int j = i + 1;j < ls.size();j++){
//           Point pInter = intersecLines(ls[i],ls[j]);
//           if (isMid(pInter,ls[i]) && isMid(pInter,ls[j]))
//               ans++;
//        }
//    }

//    cout << ans << endl;

    return 0;
}
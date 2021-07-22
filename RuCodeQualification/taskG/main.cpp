#include <iostream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

double dist(int x1,int y1,int x2,int y2){
    double res = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
//    cout << res << endl;
    return res;
}

int main() {
    multiset<int>x,y;
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    pair<int,int>a,b,c;
    if (abs(dist(x1,y1,x2,y2) - dist(x2,y2,x3,y3)) < 0.005){
        a.first = x1;
        a.second = y1;
        b.first = x2;
        b.second = y2;
        c.first = x3;
        c.second = y3;
    }
    else if(abs(dist(x1,y1,x2,y2) - dist(x1,y1,x3,y3)) < 0.005){
        b.first = x1;
        b.second = y1;
        a.first = x2;
        a.second = y2;
        c.first = x3;
        c.second = y3;
    }
    else{
        a.first = x1;
        a.second = y1;
        c.first = x2;
        c.second = y2;
        b.first = x3;
        b.second = y3;
    }

    double xo,yo;
    xo = (double)(a.first + c.first)/2;
    yo = (double)(a.second + c.second)/2;

    double ansx = 2*xo - b.first;
    double ansy = 2*yo - b.second;

    cout << ansx << ' ' << ansy << endl;

    return 0;
}
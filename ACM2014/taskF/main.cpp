#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long double;

const long double EPS = 0.01;

double pointsDist(ll x1,ll y1,ll x2,ll y2){
    return hypot(x1-x2,y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int xa,ya,xb,yb,xc,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll d,v;
    cin >> d >> v;
    int depH,depMin;
    int durH,durMin;
    char c;
    cin >> depH >> c >> depMin;
    cin >> durH >> c >> durMin;
    ll w;
    cin >> w;

    //=======
    ll adurSec = 0;
    ll ac = (pointsDist(xa,ya,xc,yc)/v)*3600;
    ll cb = (pointsDist(xc,yc,xb,yb)/v)*3600;
    adurSec = ac + cb + d*60;

    //========
    ll cdurSec = 0;
    cdurSec = (pointsDist(xa,ya,xb,yb)/w)*3600;

    if ((xc - xa) * (yb - ya) - (xb - xa)*(yc - ya) == 0){
        cdurSec += d*60;
    }
//    if (abs(pointsDist(xa,ya,xc,yc) + pointsDist(xc,yc,xb,yb) - pointsDist(xa,ya,xb,yb)) < EPS){
//        cdurSec += d*60;
//    }


    ll bdurSec = 0;
    bdurSec += ((depH - 9)*60 + depMin)*60;
    bdurSec += (durH*60 + durMin)*60;

//    cout << adurSec << endl;
//    cout << bdurSec << endl;
//    cout << cdurSec << endl;

    ll mn = min(min(adurSec,bdurSec),cdurSec);
//    cout << mn << endl;


    if (abs(mn - adurSec) < EPS){
        cout << "Alex" << endl;
    }
    else if (abs(mn - bdurSec) < EPS){
        cout << "Dmitry" << endl;
    }
    else
        cout << "Petr" << endl;

    return 0;
}

//a - alex
//b - dmitriy
//c - Petr


//10 0 0 0 20 0
//0 10
//09:01 00:01
//10
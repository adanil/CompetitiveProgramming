#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
using ld = long double;

struct Vec{
    ld x;
    ld y;
};

Vec operator - (Vec a,Vec b){
    return Vec{a.x-b.x,a.y-b.y};
}

ld vecmul(Vec a,Vec b){
    return (a.x * b.y - b.x * a.y);
}
ld scalMul(Vec a,Vec b){
    return (a.x * b.x + a.y * b.y);
}

int sign(ld x){
    if (x == 0)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}
bool isOnSegment(Vec p,Vec p1,Vec p2){
    return vecmul(p - p1,p2-p1) == 0 && scalMul(p1 - p,p2 - p) <= 0;
}
bool areParallel(Vec a,Vec b){
    return vecmul(a,b) == 0;
}



bool areIntersecting(Vec p1,Vec p2,Vec p3,Vec p4){
    if (areParallel(p2 - p1,p4 - p3)){
        return isOnSegment(p1,p3,p4) || isOnSegment(p2,p3,p4) ||
               isOnSegment(p3,p1,p2) || isOnSegment(p4,p1,p2);
    }
    else{
        return sign(vecmul(p2-p1,p4-p1)) * sign(vecmul(p2-p1,p3-p1)) <= 0 &&
               sign(vecmul(p4-p3,p1-p3)) * sign(vecmul(p4-p3,p2-p3)) <= 0;
    }
}


//ld sq (const vector<Vec> & fig)
//{
//    ld res = 0;
//    for (unsigned i=0; i<fig.size(); i++)
//    {
//        Vec p1 = i ? fig[i-1] : fig.back(),p2 = fig[i];
//        res += (tr1.x - tr2.x) * (tr1.y + tr2.y);
//    }
//    return fabs (res) / 2;
//}


ld triangle_area_2 (Vec tr1, Vec tr2, Vec tr3) {
    return (tr2.x - tr1.x) * (tr3.y - tr1.y) - (tr2.y - tr1.y) * (tr3.x - tr1.x);
}

bool clockwise (Vec tr1,Vec tr2,Vec tr3) {
    cout << triangle_area_2 (tr1, tr2, tr3) << endl;
    return triangle_area_2 (tr1, tr2, tr3) <= 0;
}



int main() {
    Vec tr1,tr2,tr3,p;
    cin >> tr1.x >> tr1.y;
    cin >> tr2.x >> tr2.y;
    cin >> tr3.x >> tr3.y;
    cin >> p.x >> p.y;

    ld a = (tr1.x - p.x) * (tr2.y - tr1.y) - (tr2.x - tr1.x) * (tr1.y - p.y);
    ld b = (tr2.x - p.x) * (tr3.y - tr2.y) - (tr3.x - tr2.x) * (tr2.y - p.y);
    ld c = (tr3.x - p.x) * (tr1.y - tr3.y) - (tr1.x - tr3.x) * (tr3.y - p.y);

    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        cout << "In" << endl;
    else
        cout << "Out" << endl;


    return 0;
}
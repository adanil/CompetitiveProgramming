#include <iostream>
#include <cmath>
#include <iomanip>

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



int main() {
    Vec p1,p2,p3,p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    if (areIntersecting(p1,p2,p3,p4))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
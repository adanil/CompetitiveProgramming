#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using ld = long double;

struct Vec {
    ld x;
    ld y;
};

Vec operator-(Vec a, Vec b) {
    return Vec{a.x - b.x, a.y - b.y};
}

ld vecmul(Vec a, Vec b) {
    return (a.x * b.y - b.x * a.y);
}

ld scalMul(Vec a, Vec b) {
    return (a.x * b.x + a.y * b.y);
}

int sign(ld x) {
    if (x == 0)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}

bool isOnSegment(Vec p, Vec p1, Vec p2) {
    return vecmul(p - p1, p2 - p1) == 0 && scalMul(p1 - p, p2 - p) <= 0;
}

bool areParallel(Vec a, Vec b) {
    return vecmul(a, b) == 0;
}


bool areIntersecting(Vec p1, Vec p2, Vec p3, Vec p4) {
    if (areParallel(p2 - p1, p4 - p3)) {
        return isOnSegment(p1, p3, p4) || isOnSegment(p2, p3, p4) ||
               isOnSegment(p3, p1, p2) || isOnSegment(p4, p1, p2);
    } else {
        return sign(vecmul(p2 - p1, p4 - p1)) * sign(vecmul(p2 - p1, p3 - p1)) <= 0 &&
               sign(vecmul(p4 - p3, p1 - p3)) * sign(vecmul(p4 - p3, p2 - p3)) <= 0;
    }
}


struct ang {
    ld a, b;
};

bool operator<(const ang &p, const ang &q) {
    if (p.b == 0 && q.b == 0)
        return p.a < q.a;
    return p.a * 1ll * q.b < p.b * 1ll * q.a;
}

ld sq(Vec &a, Vec &b, Vec &c) {
    return a.x * 1ll * (b.y - c.y) + b.x * 1ll * (c.y - a.y) + c.x * 1ll * (a.y - b.y);
}


int main() {
    Vec pnt;
    int n;
    cin >> n >> pnt.x >> pnt.y;
    vector<Vec> p(n);
    int zero_id = 0;
    ld x_max = 0,y_max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        if (p[i].x < p[zero_id].x || (p[i].x == p[zero_id].x && p[i].y < p[zero_id].y))
            zero_id = i;
        x_max = max(x_max,p[i].x);
        y_max = max(y_max,p[i].y);
    }

//    if (n == 1){
//        if (p[0].x == pnt.x && p[0].y == pnt.y)
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
//        return 0;
//    }
//    if (n == 2){
//        if (areIntersecting(p[0],p[1],pnt,Vec{pnt.x+1,pnt.y+1}))
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
//        return 0;
//    }

    int cntIn = 0;
    int cntOut = 0;

    x_max += 1;
    y_max = pnt.y + 1;
        Vec nwPoint{x_max, y_max};

        int intersecting = 0;
        for (int i = 0; i < n - 1; i++) {
            if (areIntersecting(p[i], p[i + 1], pnt, nwPoint))
                intersecting++;
        }
//        if (areIntersecting(p[n - 1], p[0], pnt, nwPoint))
//            intersecting++;

        if (intersecting % 2 == 1)
            cntIn++;
        else
            cntOut++;


    if (cntIn > cntOut)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



//



//    Vec zero = p[zero_id];
//    rotate(p.begin(), p.begin() + zero_id, p.end());
//    p.erase(p.begin());
//    --n;
//
//    vector<ang> a(n);
//    for (int i = 0; i < n; ++i) {
//        a[i].a = p[i].y - zero.y;
//        a[i].b = p[i].x - zero.x;
//        if (a[i].a == 0)
//            a[i].b = a[i].b < 0 ? -1 : 1;
//    }
//
//
//    Vec q; // очередной запрос
//    q = pnt;
//    bool in = false;
//    if (q.x >= zero.x)
//        if (q.x == zero.x && q.y == zero.y)
//            in = true;
//        else {
//            ang my = {q.y - zero.y, q.x - zero.x};
//            if (my.a == 0)
//                my.b = my.b < 0 ? -1 : 1;
//            vector<ang>::iterator it = upper_bound(a.begin(), a.end(), my);
//            if (it == a.end() && my.a == a[n - 1].a && my.b == a[n - 1].b)
//                it = a.end() - 1;
//            if (it != a.end() && it != a.begin()) {
//                int p1 = int(it - a.begin());
//                if (sq(p[p1], p[p1 - 1], q) <= 0)
//                    in = true;
//            }
//        }
//    if (in)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
        return 0;
}
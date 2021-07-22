#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

const auto ready = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cout << std::fixed << std::setprecision(12);
    return 1;
}();

long double testY = 533;
long double testX = 1000;
//
long double prevDist = 1e10;

bool query(ll x, ll y) {
//    cout << "pow: " << pow(y - testY,2) << endl;
//    cout << "PREV DIST " << prevDist  << ' ' << (y - testY)*(y - testY) + (x - testX)*(x - testX) << setprecision(6) << endl;
    bool result;
    cout << x << ' ' << y << '\n';
    cout.flush();
    cin >> result;
//    result = prevDist > (y - testY) * (y - testY) + (x - testX) * (x - testX);
//    prevDist = (y - testY) * (y - testY) + (x - testX) * (x - testX);
//    cout << "ans: "<< result << endl;
    return result;
}


int main() {
    ready;
//    for (ll i = 1000000;i < 1000000000;i++)
//        for (ll j = 1000000;j < 1000000000;j++) {
//            testX = i;
//            testY = j;
    ll maxY = 1000000000;
    ll maxX = 1000000000;
    ll x = 0, y = 0;
    bool down = true;
    bool first = true;
    bool res = query(x, y);
    res = query(x, maxY);
    bool prevQ = true;
    bool find = false;
    bool skip = false;
    while (!find) {
        if (first) {
            if (res) {
                y = (maxY + y) / 2;
                query(x, maxY);
                res = query(x, y);
                down = false;
            } else {
                maxY = (maxY + y) / 2;
                query(x, y);
                res = query(x, maxY);
                down = true;
            }
            first = false;
        } else {
            if (y + 1 >= maxY) {
                find = true;
            } else {
                prevQ = res;
                if (down) {
//                    cout << "down" << endl;
                    if (res) {
                        y = (maxY + y) / 2;
                        query(x, maxY);
                        res = query(x, y);
                        down = false;
                    } else {
                        maxY = (maxY + y) / 2;
                        query(x, y);
                        res = query(x, maxY);
                        down = true;
                    }
                } else {
//                    cout << "not down" << endl;
                    if (res) {
                        maxY = (maxY + y) / 2;
                        query(x, y);
                        res = query(x, maxY);
                        down = true;
                    } else {
                        y = (maxY + y) / 2;
                        query(x, maxY);
                        res = query(x, y);
                        down = false;
                    }
                }
            }
        }
    }
    ll ansY = -1;
    if (y + 1 == maxY) {
        query(x, y);
        if (query(x, y + 1))
            ansY = maxY;
        else
            ansY = y;
    } else {
        ansY = (maxY + y) / 2;
    }
//    cout <<"ANS Y:" << ansY << endl;


    //----x
    find = false;
    first = true;
    res = query(x, ansY);
    res = query(maxX, ansY);

    while (!find) {
        if (first) {
            if (res) {
                x = (maxX + x) / 2;
                query(maxX, ansY);
                res = query(x, ansY);
                down = false;
            } else {
                maxX = (maxX + x) / 2;
                query(x, ansY);
                res = query(maxX, ansY);
                down = true;
            }
            first = false;
        } else {
            if (x + 1 >= maxX) {
                find = true;
            } else {
                prevQ = res;
                if (down) {
//                    cout << "down" << endl;
                    if (res) {
                        x = (maxX + x) / 2;
                        query(maxX, ansY);
                        res = query(x, ansY);
                        down = false;
                    } else {
                        maxX = (maxX + x) / 2;
                        query(x, ansY);
                        res = query(maxX, ansY);
                        down = true;
                    }
                } else {
//                    cout << "not down" << endl;
                    if (res) {
                        maxX = (maxX + x) / 2;
                        query(x, ansY);
                        res = query(maxX, ansY);
                        down = true;
                    } else {
                        x = (maxX + x) / 2;
                        query(maxX, ansY);
                        res = query(x, ansY);
                        down = false;
                    }
                }
            }
        }
    }

    ll ansX = -1;
    if (x + 1 == maxX) {
        query(x, ansY);
        if (query(x + 1, ansY))
            ansX = maxX;
        else
            ansX = x;
    } else {
        ansX = (maxX + x) / 2;
    }
    cout << "A " << ansX << ' ' << ansY << endl;
//    if (testX == ansX && testY == ansY)
//        cout << "OK" << endl;
//    else {
//        cout << "ERROR!" << endl;
//        cout << testX << ' ' << testY << endl;
//        cout << "A " << ansX << ' ' << ansY << endl;
//        return 0;
//    }
//        }



    return 0;
}
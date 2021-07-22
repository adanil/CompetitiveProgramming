#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;
using ll = long long;

vector<ll>x,y;

struct Point{
    int x;
    int y;
};

struct Rectangle{
    Point p1;
    Point p2;

    Point compressed_p1;
    Point compressed_p2;
};

int compress_x_coord(int a){
    return lower_bound(x.begin(),x.end(),a) - x.begin();
}

int compress_y_coord(int a){
    return lower_bound(y.begin(),y.end(),a) - y.begin();
}

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    ll n;
    cin >> n;
    vector<Rectangle> recs(n);
    for (int i = 0;i < n;i++){
        cin >> recs[i].p1.x >> recs[i].p1.y >> recs[i].p2.x >> recs[i].p2.y;
        x.push_back(recs[i].p1.x); x.push_back(recs[i].p2.x);
        y.push_back(recs[i].p1.y); y.push_back(recs[i].p2.y);

//        if (recs[i].p1.x > recs[i].p2.x || (recs[i].p1.x == recs[i].p2.x && recs[i].p1.y > recs[i].p2.y)){
//            Point t = recs[i].p1;
//            recs[i].p1 = recs[i].p2;
//            recs[i].p2 = t;
//        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.resize(unique(x.begin(),x.end()) - x.begin());
    y.resize(unique(y.begin(),y.end()) - y.begin());

    int minX = 0,maxX = x.size();
    int minY = 0,maxY = y.size();

    for (int i = 0;i < n;i++){
        recs[i].compressed_p1.x = compress_x_coord(recs[i].p1.x);
        recs[i].compressed_p1.y = compress_y_coord(recs[i].p1.y);
        recs[i].compressed_p2.x = compress_x_coord(recs[i].p2.x);
        recs[i].compressed_p2.y = compress_y_coord(recs[i].p2.y);
    }

    ll ans = 0;

    vector<vector<set<int>>>table(maxX,vector<set<int>>(maxY));

    set<set<int>> res;

    for (int i = 0;i < n;i++){
        for (int xcoord = min(recs[i].compressed_p1.x,recs[i].compressed_p2.x);xcoord < max(recs[i].compressed_p1.x,recs[i].compressed_p2.x);xcoord++){
            for (int ycoord = min(recs[i].compressed_p1.y,recs[i].compressed_p2.y);ycoord < max(recs[i].compressed_p1.y,recs[i].compressed_p2.y);ycoord++){
                table[xcoord][ycoord].insert(i);
            }
        }
    }



    for (int i = 0;i < maxX;i++){
        for (int j = 0;j < maxY;j++) {
            if (!table[i][j].empty()) {
                res.insert(table[i][j]);
            }
        }
    }
    cout << res.size() + 1 << endl;



    return 0;
}
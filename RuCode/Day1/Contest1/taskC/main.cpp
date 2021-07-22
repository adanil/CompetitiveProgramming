#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int INF = 1000000000;

struct edge{
    int from;
    int to;
    int w;
};

double Prim(int n,vector<vector<double>>gr){
    vector<bool> used (n);
    vector<double> dist(n,INF);
    dist[0] = 0;
    double ans = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (v == -1)
            break;
        ans += dist[v];
        used[v] = true;


        for (int to=0; to<n; ++to)
            if (gr[v][to] < dist[to]) {
                dist[to] = gr[v][to];
            }
    }
    return ans;

}

struct Point{
    int x;
    int y;
};

double distPoints(Point a,Point b){
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

int main() {
    int n;
    cin >> n;
    vector<Point>points(n);
    vector<vector<double>>gr(n,vector<double>(n,INF));
    for (int i = 0;i < n;i++){
        cin >> points[i].x >> points[i].y;
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            if (i == j)
                continue;
            gr[i][j] = distPoints(points[i],points[j]);
            gr[j][i] = distPoints(points[i],points[j]);
        }
    }
    cout << fixed << setprecision(9) << Prim(n,gr) << endl;
    return 0;
}
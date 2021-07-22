#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>


using namespace std;
using ll = long long;

int n;
const int INF = 1000000000;
vector<vector<int>>g;
vector<char>used;


void rec(int x,int y,int xprev,int yprev){
    if (used[n*y + x])
        return;
    if (xprev != -1 && yprev != -1)
        g[n*y + x].push_back(n*yprev + xprev);
    used[n*y + x] = 1;
    if (x + 2 <= n){
        if (y - 1 >= 1)
            if (!(x + 2 == xprev && y - 1 == yprev)){
                g[n * y + x].push_back((x+2) + (n * (y-1)));
                rec(x+2,y-1,x,y);
            }
        if (y + 1 <= n)
            if (!(x + 2 == xprev && y + 1 == yprev)){
                g[n * y + x].push_back((x+2) + (n * (y+1)));
                rec(x+2,y+1,x,y);
            }
    }
    if (x - 2 >= 1){
        if (y - 1 >= 1)
            if (!(x - 2 == xprev && y - 1 == yprev)){
                g[n * y + x].push_back((x-2) + (n *(y-1)));
                rec(x-2,y-1,x,y);
            }
        if (y + 1 <= n)
            if (!(x - 2 == xprev && y + 1 == yprev)){
                g[n * y + x].push_back((x-2) + (n * (y+1)));
                rec(x-2,y+1,x,y);
            }
    }




    if (y + 2 <= n){
        if (x - 1 >= 1)
            if (!(y + 2 == yprev && x - 1 == xprev)){
                g[n * y + x].push_back((x-1) + (n * (y+2)));
                rec(x-1,y+2,x,y);
            }
        if (x + 1 <= n)
            if (!(y + 2 == yprev && x + 1 == xprev)){
                g[n * y + x].push_back((x+1) + (n * (y+2)));
                rec(x+1,y+2,x,y);
            }
    }


    if (y - 2 >= 1){
        if (x - 1 >= 1)
            if (!(y - 2 == yprev && x - 1 == xprev)){
                g[n * y + x].push_back((x-1)+ (n *(y-2)));
                rec(x-1,y-2,x,y);
            }
        if (x + 1 <= n)
            if (!(y - 2 == yprev && x + 1 == xprev)){
                g[n * y + x].push_back((x+1) + (n * (y-2)));
                rec(x+1,y-2,x,y);
            }
    }

    return;


}

queue<int>q;
vector<int>dist;



void bfs(){
    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (auto to : g[v]){
            if (!used[to]){
                q.push(to);
                used[to] = 1;
            }
            dist[to] = min(dist[to],dist[v] + 1);
        }
    }
}

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    fin >> n;
    int xh,yh,xt,yt;
    fin >> xh >> yh >> xt >> yt;
    g.resize(n*n + 2 * n);
    dist.resize(n*n + 2 * n,INF);
    used.resize(n*n + 2 * n,0);
    rec(xh,yh,-1,-1);
    used.clear();
    used.resize(n*n + 2*n,0);
    int start = n * yh + xh;
    int target = n * yt + xt;
    q.push(start);
    used[start] = 1;
    dist[start] = 0;
    bfs();

    fout << dist[target] << endl;
    return 0;
}
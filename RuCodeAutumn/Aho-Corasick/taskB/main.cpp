#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
using ll = long long;

struct vertex {
    int next[2];
    bool leaf;
    int p;
    char pch;
    int link;
    int go[2];
    char c;
    vector<int>s_inds;
};

vertex t[30000 + 1];
int sz;
int maxV = 30000 + 1;

void init() {
    t[0].p = t[0].link = -1;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

void add_string (const string & s,int ind) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = s[i]-'0';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].p = v;
            t[sz].pch = c;
            t[sz].c = s[i];
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].s_inds.push_back(ind);
}

int go (int v, char c);

int get_link (int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go (int v, char c) {
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return t[v].go[c];
}

vector<char>used;
bool fl = false;



void dfs(int v){
    if (v < 0 || v > used.size() - 1)
        return;
    if (used[v] == 1){
        fl = true;
        return;
    }
    used[v] = 1;
    for (int i = 0;i < 2;i++){
        if (!t[go(v,i)].leaf && go(v,i) != 0 && go(v,i) != -1){
            bool notTerm = true;
            int vm = go(v,i);
            while(vm != 0){
                if (t[t[vm].link].leaf) {
                    notTerm = false;
                    break;
                }
                vm = t[vm].link;
            }
            if (notTerm){
                if (go(v,i) != 0 && go(v,i) != -1 && used[go(v,i)] != 2)
                    dfs(go(v,i));
            }

        }

    }
    used[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;

    init();

    for (int i = 0;i < m;i++){
        string s;
        cin >> s;
        add_string(s,i);
    }

    for (int i = 0;i < maxV;i++){
        go(i,'0' - '0');
        go(i,'1' - '0');
    }

    used.resize(maxV,0);

    dfs(0);
    if (fl)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;



    return 0;
}



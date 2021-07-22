#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;
using ll = long long;

struct vertex {
    int next[26];
    bool leaf;
    int p;
    char pch;
    int link;
    int go[26];
    char c;
    vector<int>s_inds;
};

vertex t[1000000    +1];
int sz;

void init() {
    t[0].p = t[0].link = -1;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

void add_string (const string & s,int ind) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = s[i]-'a';
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

int main() {
    ios_base::sync_with_stdio(false);
    string text;
    cin >> text;
    int m;
    cin >> m;

    init();

    for (int i = 0;i < m;i++){
        string s;
        cin >> s;
        add_string(s,i);

    }

    vector<bool>ans(m);
    int st = 0;
    for (auto c : text){
        st = go(st,c - 'a');
            int vmatch = st;
            while (vmatch != 0){
                if (t[vmatch].leaf) {
                    for (auto ind : t[vmatch].s_inds)
                        ans[ind] = true;
                }
                vmatch = get_link(vmatch);
            }

    }

    for (auto b : ans){
        if (b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }


    return 0;
}



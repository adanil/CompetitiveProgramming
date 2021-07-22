#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

struct Vertex{
    vector<Vertex*> ar;
    bool term = false;
    char name;

    Vertex(char c){
        ar.resize(26, nullptr);
        name = c;
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    Vertex* root = new Vertex('!');
    Vertex* curr = root;

    Vertex* revRoot = new Vertex('!');
    Vertex* revCurr = revRoot;
    vector<string> data(n);
    for (int i = 0;i < n;i++){
        curr = root;
        revCurr = revRoot;
        cin >> data[i];
        for (auto c : data[i]){
            if (curr->ar[c - 'a'] == nullptr){
                curr->ar[c - 'a'] = new Vertex(c);
                curr = curr->ar[c-'a'];
            }
            else
                curr = curr->ar[c - 'a'];
        }
        curr->term = true;

        for (int j = data[i].size() - 1;j >= 0;j--){
            char c = data[i][j];
            if (revCurr->ar[c - 'a'] == nullptr){
                revCurr->ar[c - 'a'] = new Vertex(c);
                revCurr = revCurr->ar[c-'a'];
            }
            else
                revCurr = revCurr->ar[c - 'a'];
        }
        revCurr->term = true;
    }

    for (int i = 0;i < n;i++){
        ll ans = 0;
        string s = data[i];
        curr = root;
        revCurr = revRoot;
        vector<bool> frw(s.size(), false);
        for (int j = 0;j < s.size() - 1;j++){
            if (curr->ar[s[j] - 'a'] != nullptr){
                curr = curr->ar[s[j] - 'a'];
                if (curr->term)
                    frw[j + 1] = true;
            }
        }

        for (int j = s.size() - 1;j > 0;j--){
            if (revCurr->ar[s[j] - 'a'] != nullptr){
                revCurr = revCurr->ar[s[j] - 'a'];
                if (revCurr->term && frw[j])
                    ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}


//x
//xx
//xxx
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Node{
    vector<Node*> ar;
    int dp = 0;
    char c;
    bool term = false;
    int cnt = 0;
    Node(char j){
        c = j;
        ar.resize(26, nullptr);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    Node* root = new Node('!');
    Node* curr = root;
    for (int i = 0;i < n;i++){
        cin >> s;
        try{
            int k = stoi(s);
            curr = root;
            string ans;
            while (k > 0){
                for (int j = 0;j < 26;j++){
                    if (curr->ar[j] == nullptr)
                        continue;
                    if (curr->ar[j]->dp  < k)
                        k -=curr->ar[j]->dp;
                    else{
                        curr = curr->ar[j];
                        ans += (char)('a' + j);
                        if (curr->term){
                            k -= curr->cnt;
                        }
                        if (curr->term && k <= 0){
                            cout << ans << endl;
                        }
                        break;
                    }
                }
            }
        }
        catch (...){
            curr = root;
            for (int j = 0;j < s.size();j++){
                if(curr->ar[s[j] - 'a'] == nullptr){
                    Node* el = new Node(s[j]);
                    curr->ar[s[j] - 'a'] = el;
                    curr->dp++;
                    curr = curr->ar[s[j] - 'a'];
                }
                else{
                    curr->dp++;
                    curr = curr->ar[s[j] - 'a'];
                }
            }
            curr->term = true;
            curr->dp++;
            curr->cnt++;
        }
    }
    return 0;
}
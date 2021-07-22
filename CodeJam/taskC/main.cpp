#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct activity{
    int start;
    int end;
    int ind;
};

int main() {

    string imp = "IMPOSSIBLE";

    int t;
    cin >> t;
    int q = t;

    while (t--){
        int n;
        cin >> n;
        vector<char> ans(n);
        vector<activity> act(n);
        for (int i = 0;i < n;i++) {
            cin >> act[i].start >> act[i].end;
            act[i].ind = i;
        }

        sort(act.begin(),act.end(),[](activity a,activity b){ return a.start < b.start;});

        cout << "Case #" << q-t << ": ";

        int cameron = 0;
        int jamie = 0;

        bool fl = false;

        for (int i = 0;i < n;i++){
            if (cameron <= act[i].start) {
                ans[act[i].ind] =  'C';
                cameron = act[i].end;
            }
            else if (jamie <= act[i].start){
                ans[act[i].ind] =  'J';
                jamie = act[i].end;
            }
            else{
                cout << imp << endl;
                fl = true;
                break;
            }
        }
        if (!fl) {
            for (char c : ans)
                cout << c;
            cout << endl;
        }


    }


    return 0;
}
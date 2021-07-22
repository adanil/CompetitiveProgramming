#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<list<int> *> res(n, nullptr);
        for (int i = 0; i < n; i++) {
            res[i] = new list<int>(1, i);
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (res[a]->size() > res[b]->size()) {
                res[a]->insert(res[a]->end(), res[b]->begin(), res[b]->end());
                list<int> *pt1 = res[a];
                for (auto item : *res[b]) {
                    res[item] = pt1;
                }
            }
            else{
                res[b]->insert(res[b]->begin(), res[a]->begin(), res[a]->end());
                list<int> *pt1 = res[b];
                for (auto item : *res[a]) {
                    res[item] = pt1;
                }
            }
        }
        for (int j = 0;j < n;j++) {
            if (res[j]->size() == n) {
                for (auto it = res[j]->begin(); it != res[j]->end(); it++)
                    cout << *it + 1 << ' ';
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    int q = t;

    while(t--){
        string s;
        cin >> s;

        cout << "Case #" << q-t << ": ";

        vector<int>d;
        for (char c : s){
            d.push_back(c - '0');
        }
        int prLeft = 0;
        int prRight = 0;
        for (int i = 0;i < d.size();i++){
            if (d[i] > prLeft) {
                int prev = prLeft;
                prLeft = d[i];
                for (int j = 0;j < prLeft - prev;j++)
                    cout << '(';
                cout << d[i];

            }
            else if (d[i] < prLeft){
                int prev = prLeft;
                prLeft = d[i];
                for (int j = 0;j < prev - prLeft;j++)
                    cout << ')';
                cout << d[i];
            }
            else
                cout << d[i];
        }
        for (int j = 0;j < prLeft;j++)
            cout << ')';
        cout << endl;
    }


    return 0;
}
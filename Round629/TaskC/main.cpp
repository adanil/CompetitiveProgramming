#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0;i < t;i++){
        int n;
        string x;
        cin >> n;
        cin >> x;
        bool fl = false;
        string a(n,'0'),b(n,'0');
        for (int j = 0;j < n;j++){
            if (x[j] == '2'){
                if (!fl) {
                    a[j] = '1';
                    b[j] = '1';
                }
                else{
                    a[j] = '0';
                    b[j] = '2';
                }
            }
            else if (x[j] == '1'){
                if (!fl) {
                    fl = true;
                    a[j] = '1';
                    b[j] = '0';
                }
                else{
                    a[j] = '0';
                    b[j] = '1';
                }
            } else
                continue;
        }

        cout << a << endl << b << endl;

    }
    return 0;
}
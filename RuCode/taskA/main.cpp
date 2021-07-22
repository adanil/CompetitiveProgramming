#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin,s);

    for (int i = 0;i < s.size();i++){
        if (s[i] != ' ' && (s[i] < 97 || s[i] > 122)){
            cout << "unsafe" << endl;
            return 0;
        }
    }

    int spaces = 0;
    for (int i = 0; i < s.size();i++){
        if (s[i] >= 97 && s[i] <= 122){
            if (i != 0){
                if (spaces < 2){
                    cout << "unsafe" << endl;
                    return 0;
                }
                spaces = 0;
            }
        }
        else
            spaces++;
    }

    cout << "safe" << endl;

    return 0;
}
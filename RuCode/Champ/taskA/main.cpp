#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int day = stoi(s.substr(s.size()-4,2));
    int month = stoi(s.substr(s.size()-2,2));
    cout << day << ' ' << month << endl;

    return 0;
}
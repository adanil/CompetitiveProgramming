#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ifstream in_file;

    in_file.open("tst.txt", std::ios::in);


    char sym;
    string g_file_str,h_file_str;
    while (!in_file.eof()) {
//        if (in_file.good()) {
            in_file.get(sym);
            cout << (int)sym << endl;

            if ((int)sym % 2 == 0 && (int)sym % 4 == 0 && (int)sym % 6 != 0) {
                g_file_str.push_back(sym);
            }
            else
                h_file_str.push_back(sym);
//        }
    }
    in_file.close();

    cout << g_file_str << endl;
    cout << h_file_str << endl;
    return 0;
}
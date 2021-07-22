#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> a = {1, 2, 3, 6, 9, 18, 30, 56, 99, 186, 335, 630, 1161, 2182, 4080, 7710, 14532, 27594, 52377, 99858, 190557, 364722, 698870, 1342176, 2580795, 4971008};
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        long long b;
        cin >> b;
        if (find(a.begin(),a.end(),b) != a.end())
            a.erase(find(a.begin(),a.end(),b));
    }
    cout << 26 - n << endl;
    for (int i = 0;i < a.size();i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
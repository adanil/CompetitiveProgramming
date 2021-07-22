#include <iostream>
#include <set>
#include <string>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    set<string>st;
    for (int i = 0;i < n;i++){
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
    return 0;
}
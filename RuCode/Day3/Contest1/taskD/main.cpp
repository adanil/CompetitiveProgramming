#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == ""){
        cout << "YES" << endl;
        return 0;
    }
    stack<char> st;
    for (int i = 0;i < s.size();i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if (s[i] == ')'){
            if (st.empty()){
                cout << "NO" << endl;
                return 0;
            }
            if (st.top() != '(') {
                cout << "NO" << endl;
                return 0;
            }
            else
                st.pop();
        }
        else if (s[i] == ']'){
            if (st.empty()){
                cout << "NO" << endl;
                return 0;
            }
            if (st.top() != '['){
                cout << "NO" << endl;
                return 0;
            }
            else
                st.pop();
        }
        else if (s[i] == '}'){
            if (st.empty()){
                cout << "NO" << endl;
                return 0;
            }
            if (st.top() != '{'){
                cout << "NO" << endl;
                return 0;
            }
            else
                st.pop();
        }

    }
    if (st.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

struct st{
    int sec;
    int min;
    int hour;
    ll day;
    ll month;
    ll year;
    string s;
    string s2;
};

int main() {
    ll n;
    cin >> n;
    vector<st>a(n);
    for(int i = 0;i < n;i++){
        char c;
        string s,s2;
        cin >> s >> s2;
        a[i].s = s;
        a[i].s2 = s2;
//        for (int j = 0;j < s.size();j++){
            a[i].sec = stoi(s.substr(0,2));
            a[i].min = stoi(s.substr(3,2));
            a[i].hour = stoi(s.substr(6,2));
            a[i].day = stoi(s2.substr(0,2));
            a[i].month = stoi(s2.substr(3,2));
            a[i].year = stoi(s2.substr(6,4));

//        }
//        cin >> a[i].sec >> c >> a[i].min >> c >> a[i].hour >> a[i].day >> c >> a[i].month >> c >> a[i].year;
    }
    sort(a.begin(),a.end(),[](st a,st b){
        if (a.year > b.year){
            return true;
        }
        else if (a.year == b.year){
            if (a.month > b.month)
                return true;
            else if (a.month == b.month){
                if (a.day > b.day)
                    return  true;
                else if (a.day == b.day){
                    if (a.hour > b.hour)
                        return true;
                    else if (a.hour == b.hour){
                        if (a.min > b.min)
                            return true;
                        else if (a.sec > b.sec){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    });


    for (int i = n - 1;i >= 0;i--){
//        cout << a[i].sec << ':' << a[i].min << ':' << a[i].hour << ' ' << a[i].day << '.' << a[i].month << '.' << a[i].year << endl;
        cout << a[i].s << ' ' << a[i].s2 << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>



using namespace std;



struct ps{
    long long w;
    long long t;
    long long num;
    long long ans;

};






int main() {
    long long n;
    cin >> n;

    vector<ps> persons(n);

    for (int i = 0;i < n;i++){
        cin >> persons[i].t >> persons[i].w;
        persons[i].num = i;
    }

    sort(persons.begin(),persons.end(),[](const ps& p1,const ps& p2){
        return p1.w < p2.w;
    });


    long long prev = persons[0].w * persons[0].t;
    persons[0].ans = prev;
    for (int i = 1;i < n;i++){
        if (i > 0){
            if (persons[i].w * persons[i].t< prev)
                persons[i].ans = prev;
            else{
                prev = persons[i].w * persons[i].t;
                persons[i].ans = prev;
            }
        }
    }

    sort(persons.begin(),persons.end(),[](const ps& p1,const ps& p2){
        return p1.num < p2.num;
    });


    for (int i = 0;i < n;i++)
        cout << persons[i].ans << endl;


    return 0;
}
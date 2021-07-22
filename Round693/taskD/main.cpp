#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<ll>a(n);
       vector<ll>alice,bob;
       for (int i = 0;i < n;i++){
           cin >> a[i];
           if (a[i] % 2 == 0)
               alice.push_back(a[i]);
           else
               bob.push_back(a[i]);
       }

       int alpnt = alice.size() - 1;
       int bobpnt = bob.size() - 1;
       sort(alice.begin(),alice.end());
       sort(bob.begin(),bob.end());

       ll alScore = 0,bobScore = 0;
       bool step = true; //true - alice ||| false - bob
       for (int i = 0;i < n;i++){
           if (step) {
               if (alpnt < 0){
                   bobpnt--;
               }
               else if (bobpnt < 0){
                   alScore += alice[alpnt];
                   alpnt--;
               }
               else if (alice[alpnt] >= bob[bobpnt]) {
                   alScore += alice[alpnt];
                   alpnt--;
               } else {
                   bobpnt--;
               }
               step = false;
           }
           else{
               if (bobpnt < 0){
                   alpnt--;
               }
               else if (alpnt < 0){
                   bobScore += bob[bobpnt];
                   bobpnt--;
               }
               else if (alice[alpnt] <= bob[bobpnt]) {
                   bobScore += bob[bobpnt];
                   bobpnt--;
               } else {
                   alpnt--;
               }
               step = true;
           }
       }
       if (alScore > bobScore){
           cout << "Alice" << endl;
       }
       else if (alScore == bobScore){
           cout << "Tie" << endl;
       }
       else{
           cout << "Bob" << endl;
       }

    }
    return 0;
}
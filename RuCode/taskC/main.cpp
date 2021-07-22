#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<double > ans;

struct cardState{
    double value;
    bool state = false;
};


void solve(vector<cardState > cards,int len,double res){
    if (len >= cards.size()){
        ans.insert(res);
        return;
    }

    for (int i = 0;i < cards.size();i++){
        if (!cards[i].state){
            cards[i].state = true;
            solve(cards,len + 1,res + cards[i].value);
            solve(cards,len + 1,res - cards[i].value);
            solve(cards,len + 1,res * cards[i].value);
            solve(cards,len + 1,res / cards[i].value);

            double tmp = cards[i].value;

           auto it = cards.begin();
           while(it != cards.end()){
                if (it->state) {
                    it = cards.erase(it);
                    len--;
                }
                else
                    it++;
            }
           //len++;

           cardState cr;
           cr.state = true;

           cr.value = res + tmp;
           cards.push_back(cr);
           solve(cards,len + 1,cr.value);

           cards.erase(cards.end()-1);

            cr.value = res - tmp;
            cards.push_back(cr);
            solve(cards,len + 1,cr.value);

            cards.erase(cards.end()-1);

            cr.value = res * tmp;
            cards.push_back(cr);
            solve(cards,len + 1,cr.value);

            cards.erase(cards.end()-1);

            cr.value = res / tmp;
            cards.push_back(cr);
            solve(cards,len + 1,cr.value);

        }
    }

}

int main() {


    vector<cardState> cards(4);
    for (int i = 0;i < 4;i++)
        cin >> cards[i].value;

    for (int i = 0;i < 4;i++) {
        cards[0].state = false; cards[1].state = false; cards[2].state = false; cards[3].state = false;
        cards[i].state = true;
        solve(cards, 1, cards[i].value);
    }

    //cout << "size: " << ans.size() << endl;


    const int INF = 999999999;

    int minDist = INF;
    int minValue = -1;
    for (auto it = ans.begin();it != ans.end();it++){
        if (fmod(*it,1) == 0){
            if (abs(21 - *it) < minDist){
                minDist = abs(21 - *it);
                minValue = *it;
            }
            else if (abs(21 - *it) == minDist && *it < minValue)
                minValue = *it;

        }
    }

    cout << minValue << endl;

    return 0;
}
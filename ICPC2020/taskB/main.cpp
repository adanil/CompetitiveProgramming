#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<string,string>>orderPlayers;
    string nameA,nameB;
    map<string,ll> teamA,teamB;
    set<string>onCourtA,onCourtB;
    cin >> nameA;
    for (int i = 0;i < 5;i++){
        string player;
        cin >> player;
        teamA[player] = 0;
        onCourtA.insert(player);
        orderPlayers.emplace_back(nameA,player);
    }
    cin >> nameB;
    for (int i = 0;i < 5;i++){
        string player;
        cin >> player;
        teamB[player] = 0;
        onCourtB.insert(player);
        orderPlayers.emplace_back(nameB,player);
    }
    int q;
    cin >> q;
    string c;
    string teamName;
    string act;
    int points;
    string old_player,new_player;
    for (int i = 0;i < q;i++){
        cin >> c;
        cin >> teamName;
        cin >> act;
        if (act == "scored"){
            cin >> points;
            if (teamName == nameA){
                for (auto& player : onCourtA){
                    teamA[player] += points;
                }

                for (auto& player : onCourtB){
                    teamB[player] -= points;
                }
            }
            else{
                for (auto& player : onCourtB){
                    teamB[player] += points;
                }

                for (auto& player : onCourtA){
                    teamA[player] -= points;
                }
            }
        }

        else{
            cin >> old_player >> c >> new_player;

            if (teamName == nameA){
                if (teamA.count(new_player) == 0) {
                    teamA[new_player] = 0;
                    orderPlayers.emplace_back(nameA,new_player);
                }

                onCourtA.erase(onCourtA.find(old_player));
                onCourtA.insert(new_player);
            }

            else{
                if (teamB.count(new_player) == 0) {
                    teamB[new_player] = 0;
                    orderPlayers.emplace_back(nameB,new_player);
                }

                onCourtB.erase(onCourtB.find(old_player));
                onCourtB.insert(new_player);
            }

        }

    }


    for (int i = 0;i < orderPlayers.size();i++){
        string tm = orderPlayers[i].first;
        string pl = orderPlayers[i].second;
        if (tm == nameA){
            ll score = teamA[pl];
            cout << pl << " (" << nameA << ") ";
            if (score > 0)
                cout << "+" << score << endl;
            else if (score == 0)
                cout << 0 << endl;
            else
                cout << score << endl;
        }
        else{
            ll score = teamB[pl];
            cout << pl << " (" << nameB << ") ";
            if (score > 0)
                cout << "+" << score << endl;
            else if (score == 0)
                cout << 0 << endl;
            else
                cout << score << endl;
        }
    }




    return 0;
}
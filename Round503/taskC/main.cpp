#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 1000000000000000000;

struct Voter{
    ll p;
    ll c;
    ll id;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<Voter>voters(n);
    vector<vector<Voter>>party(m);

    vector<vector<int>> voteForParty(n);

    for (int i = 0;i < n;i++){
        ll p,c;
        Voter vt;
        cin >> p >> c;
        p--;
        vt.p = p;
        vt.c = c;
        vt.id = i;
        voters[i] = vt;
        party[p].push_back(vt);
    }

    bool fl1 = true;
   for (int i = 1;i < m;i++){
       if (party[i].size() >= party[0].size()) {
           fl1 = false;
           break;
       }
   }
   if (fl1){
       cout << 0 << endl;
       return 0;
   }

    for (int i = 0;i < n;i++){
        for (int j = 0;j < party.size();j++){
            if (party[j].size() == i)
                voteForParty[i].push_back(j);
        }
    }


    ll ans = INF;
    sort(voters.begin(),voters.end(),[](Voter a,Voter b){return a.c < b.c;});
    for (int i = 1;i < m;i++){
        sort(party[i].begin(),party[i].end(),[](Voter a,Voter b){return a.c < b.c;});
    }
    for (int i = 1;i < n+1;i++) {
        ll ourVotes = party[0].size();
        if (ourVotes > i)
            continue;
        vector<int> used(n,false);
        bool fl = false;
        ll locSum = 0;
        for (int j = i;j < voteForParty.size();j++){
            for (auto pt:voteForParty[j]){
                int inParty = party[pt].size();
                int q = 0;
                while (inParty >= i){
                    locSum += party[pt][q].c;
                    used[party[pt][q].id] = true;
                    inParty--;
                    q++;
                    ourVotes++;
                    if (ourVotes > i){
                        fl = true;
                        break;
                    }
                }
                if (fl)
                    break;
            }
            if (fl)
                break;
        }
        if (fl)
            continue;
        int q = 0;
        while (ourVotes < i){
            if (voters[q].p != 0 && !used[voters[q].id]){
                locSum += voters[q].c;
                ourVotes++;
            }
            q++;
        }
        ans = min(ans,locSum);
    }
    cout << ans << endl;

    return 0;
}
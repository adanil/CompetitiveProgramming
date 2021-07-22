#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>


using namespace std;
using ll = long long;

int zip_name(string name,const vector<string>& names){
    return lower_bound(names.begin(),names.end(),name) - names.begin();
}

vector<map<int,double>> conv;
map<int,vector<double>>table;
int reqValue;

void recurs(double val,int curr,int prev){
    for (auto it = conv[curr].begin();it != conv[curr].end();it++) {
        if (it->first != prev) {
            table[it->first].push_back(val * it->second);
            recurs(val*it->second,it->first,curr);
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int t = 1;
    while(n != 0){
        table.clear();
        conv.clear();
        vector<string> names;
        vector<vector<pair<ll,string>>> data(n);
        for (int i = 0;i < n;i++) {
            ll val1, val2;
            string cur1, cur2;
            string rnd;
            cin >> val1 >> cur1 >> rnd >> val2 >> cur2;
            data[i].push_back({val1,cur1});
            data[i].push_back({val2,cur2});
            names.push_back(cur1);
            names.push_back(cur2);
//            cout << val1 << cur1 << val2 << cur2 << endl;
        }
        sort(names.begin(),names.end());
        names.resize(unique(names.begin(),names.end()) - names.begin());
        conv.resize(names.size());
        for (int i = 0;i < n;i++){
            ll val1, val2;
            string cur1, cur2;
            cur1 = data[i][0].second; val1 = data[i][0].first;
            cur2 = data[i][1].second; val2 = data[i][1].first;
            int from = zip_name(cur1,names);
            int to = zip_name(cur2,names);
            conv[from][to] = (double)val1/(double)val2;
            conv[to][from] = (double)val2/(double)val1;
        }
        ll reqCnt;
        string reqVal;
        cin >> reqCnt >> reqVal;
        reqValue = zip_name(reqVal,names);
        recurs(1,reqValue,-1);

        ll answer = -1;
        string answerName;
        double diff = -1;

        for (auto it = table.begin();it != table.end();it++){
//            cout << names[it->first] << ' ';
            for (int i = 0;i < it->second.size();i++) {
//                cout << ' ' << it->second[i] << ' ';
                if (answer == -1) {
                    answer = ceil((double) reqCnt / (double) it->second[i]);
                    diff = answer - (double) reqCnt / (double) it->second[i];
                    answerName = names[it->first];
                }
                else if (ceil((double) reqCnt / (double) it->second[i]) - (double) reqCnt / (double) it->second[i] < diff){
                    answer = ceil((double) reqCnt / (double) it->second[i]);
                    diff = answer - (double) reqCnt / (double) it->second[i];
                    answerName = names[it->first];
                }
            }
//            cout << (double)reqCnt/(double)it->second[0] << endl;
        }
        cout << "Case " << t << ": " << answer << ' ' << answerName << endl;
        cin >> n;
        t++;

    }

    return 0;
}
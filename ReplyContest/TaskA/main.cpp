#include <iostream>
#include <vector>


using namespace std;

using ll = long long;


struct team
{
    int number;
    ll sumScore;
    ll sumPenalty;
};

struct log
{
    ll timestamp;
    ll teamid;
    ll problemid;
    ll inputid;
    ll scored;
};



int main() {
    long long t;
    cin >> t;
    for (long long i = 0;i < t;i++){
        long long n,l;
        cin >> n >> l;
        vector<team> teams(n);
        vector<log> logs(l);
        for (long long j = 0;j < l;j++){
            long long tmstp,team,prob,inp,scored;
            cin >> logs[j].timestamp >> logs[j].teamid >> logs[j].problemid >>
            logs[j].inputid >> logs[j].scored;
        }

        for (long long j = 0;j < l;j++){

        }

    }
    return 0;
}
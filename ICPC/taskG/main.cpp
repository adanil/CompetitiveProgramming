#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;
int mask1,mask2,mask3,mask4;

void get_mask(string net,int countBit){
    int addr1,addr2,addr3,addr4;
    int cnt = 0;
    string tmp;
    for (char c : net){
        if (c == '.'){
            if (cnt == 0)
                addr1 = stoi(tmp);
            else if(cnt == 1)
                addr2 = stoi(tmp);
            else if(cnt == 2)
                addr3 = stoi(tmp);
            cnt++;
            tmp = "";
        }
        else if (c == '/'){
            addr4 = stoi(tmp);
            break;
        }
    }
    cnt = 0;
    while (countBit > 0){
        if (countBit >= 8){
            if (cnt == 0)
                mask1 = addr1;
            else if (cnt == 1)
                mask2 = addr2;
            else if (cnt == 2)
                mask3 = addr3;
            else if (cnt == 3)
                mask4 = addr4;
            cnt++;
            countBit -= 8;
        }
        else{
            int q = 0;
            for (int i = 0;i < countBit;i++){
                q = q << 1;
                q += 1;
            }
            if (cnt == 0)
                mask1 = addr1 & q;
            else if (cnt == 1)
                mask2 = addr2 & q;
            else if (cnt == 2)
                mask3 = addr3 & q;
            else if (cnt == 3)
                mask4 = addr4 & q;
            cnt++;
            countBit = 0;
        }
    }
}

string get_wide(){
    string result;
    int pw = 1;
    for (int)

}


int main() {
    set<string> checked;

    string net;
    cin >> net;
    int countBitMask = 0;
    string tmp;
    bool fl = false;
    for (auto c : net){
        if (fl){
            tmp += c;
        }
        if (c == '/')
            fl = true;
    }
    countBitMask = stoi(tmp);
    get_mask(net,countBitMask);
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        string ipAll;
        cin >> ipAll;
        if (checked.count(ipAll) != 0)
            continue;
        if ()

    }


    return 0;
}
#include <iostream>
#include <list>


using namespace std;

int main() {
    list<int> polka;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        int cmd;
        cin >> cmd;
        int diskName;
        if (cmd == 1) {
            cin >> diskName;
            polka.push_front(diskName);
        }
        else if (cmd == 2){
            cin >> diskName;
            polka.push_back(diskName);
        }
        else if (cmd == 3){
            int out = polka.front();
            polka.pop_front();
            cout << out << " ";
        }
        else if (cmd == 4){
            int out = polka.back();
            polka.pop_back();
            cout << out << " ";
        }
    }

    return 0;
}
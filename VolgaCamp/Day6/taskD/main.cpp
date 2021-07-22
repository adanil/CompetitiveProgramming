#include <iostream>
#include <vector>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;


vector<int> new_vec;
int cur = 0;
vector<vector<int>>vec;

void generate(int ind = 0, int sum = 15)
{
    for (int i = 0; i <= sum; ++i)
    {
        new_vec.push_back(i);
        cur += i;
        if (ind < 5)
        {
            generate(ind + 1, sum - i);
        }
        else
        {
            if (cur == 15) vec.push_back(new_vec);
        }
        new_vec.pop_back();
        cur -= i;
    }
}



int main()
{
    generate();
    std::sort(all(vec), [](const vector<int>& a, const vector<int>& b) {
        bool before = true;
        for (int i = 0; i < 6; ++i)
        {
            if (a[i] > b[i])
            {
                before = false;
                break;
            }
        }
        return before;
    });
    int counter = 1;
    char s;
    int ind;
    cin >> s;
    vector<int> v(6, 0);
    while (s != 'e')
    {
        cout << "Case " << counter << ": ";
        if (s == 'm')
        {
            for(int i = 0;i < 6;i++) cin >> v[i];
            auto it = std::lower_bound(all(vec), v);
            cout << int(it - vec.begin()) << "\n";
        }
        else
        {
            cin >> ind;
            for (auto& x : vec[ind]) cout << x << " ";
            cout << "\n";
        }
        ++counter;
        cin >> s;
    }
    return 0;
}
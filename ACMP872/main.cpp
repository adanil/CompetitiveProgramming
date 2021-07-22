#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout,std::max;

bool isPrefix(const string &a,const string &b);

int main() {
    int n;
    vector<string> words;
    cin >> n;
    for (int i = 0;i < n;i++){
        string w;
        cin >> w;
        if (std::find(words.begin(),words.end(),w) == words.end())
            words.push_back(w);
    }
    std::sort(words.begin(),words.end());
    n = words.size();
    vector<int>d(n,0);
    d[0] = 1;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < i;j++){
            if (isPrefix(words[j],words[i]))
                d[i] = max(d[i],d[j] + 1);
            if (isPrefix(words[i],words[j]))
                d[j] = max(d[j],d[i] + 1);

            d[i] = max(d[i],1);
        }
    }
    cout << *std::max_element(d.begin(),d.end()) << std::endl;
    return 0;
}


/*
 * a ab bc bcd add
 * 1 2  1   2   1
 * agg ag agger a aggt
 *  1   2  3    3   4
 *  bcad bcde bca
 */

bool isPrefix(const string &a,const string &b){
    if (a == b)
        return false;
    for (size_t i = 0;i < a.size();i++)
        if (a[i] != b[i])
            return false;
    return true;
}
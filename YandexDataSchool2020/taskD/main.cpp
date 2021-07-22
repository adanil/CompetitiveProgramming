#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    set<ll>st;
    for (ll i = 0;i < n;i++){
        ll el;
        cin >> el;
        st.insert(el);
    }

    ll result = 0;
    while(st.size() > 2){
        ll bg = *st.begin();
        auto iten = st.end();
        iten--;
        iten--;
        ll x = bg + *iten;
        result += x;
        st.erase(st.begin());
        st.erase(iten);
        st.insert(x);
    }
    ll sum = 0;
    for (auto it = st.begin();it != st.end();it++){
        sum += *it;
    }
    cout << sum + result << endl;
    return 0;
}
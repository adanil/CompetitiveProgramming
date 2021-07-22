#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void merge(vector<pair<ll,ll>> &arr,ll lf,ll rf,ll ls,ll rs){
    static vector<pair<ll,ll>> tmp(arr.size());
    ll k = lf;
    ll start = lf;
    ll end = rs;
    while(lf < rf && ls < rs){
        if (arr[lf] < arr[ls]) {
            tmp[k] = arr[lf];
            lf++;
            k++;
        }
        else{
            tmp[k] = arr[ls];
            tmp[k].second += rf - lf;
            ls++;
            k++;
        }
    }
    while (lf < rf){
        tmp[k] = arr[lf];
        lf++;
        k++;
    }
    while(ls < rs){
        tmp[k] = arr[ls];
        ls++;
        k++;
    }
    for (ll i = start;i < k;i++)
        arr[i] = tmp[i];
    return;
}

void mergeSort(vector<pair<ll,ll>> &arr,ll left,ll right){
    if (left + 1 >= right)
        return;
    ll mid = (left + right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid,right);
    merge(arr,left,mid,mid,right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll,ll>>a(n);
    for (auto &el : a) {
        cin >> el.first;
        el.second = 0;
    }
    mergeSort(a,0,a.size());
    for (ll i = 0;i < n;i++){
        cout << a[i].second << ' ';
    }
    return 0;
}
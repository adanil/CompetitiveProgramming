#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


double C (int n, int k) {
    double res = 1;
    for (int i=1; i<=k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    //cout << res << endl;
    return res;
}

int main() {
    int n,k;
    cin >> n >> k;
    if (n == k){
        cout << fixed << setprecision(7) << 1.0 << endl;
        return 0;
    }

    double ans = 0;

    double allComb = C(n,k);
    //cout << allComb << endl;
    vector<vector<double>> table(n-k,vector<double>(k+1,0));

    for (int i = 0;i < n-k;i++){
        for (int j = 0; j < k+1;j++){
            table[i][j] = ((double)1/(double)allComb) * C(k+i,k-j) * C(n-(k+i),j);
        }
    }

//    for (int i = 0;i < n-k;i++){
//        for (int j = 0;j < k+1;j++){
//          ;//cout <<  table[i][j] << ' ';
//        }
//        //cout << endl;
//    }

    vector<double> d(n-k,0);

    d[n-k-1] = 0;
    for (int i = n - k - 2; i >= -1;i--){
        for (int j = 1;j < k+1;j++){
            if (i == -1){
                if ((i + j) < (n-k))
                    ans += (table[i+1][j] + table[i+1][j] * d[i + j]);
            }
            else {
                if ((i + j) < (n-k))
                    d[i] += (table[i + 1][j] + table[i + 1][j] * d[i + j]);
            }
        }
        if (i == -1){
            ans += (table[i+1][0]);
            ans /= (1 - table[i+1][0]);
        }
        else {
            d[i] += (table[i + 1][0]);
            d[i] /= (1 - table[i + 1][0]);
        }
        //cout << "D" << i << " = " << d[i] << endl;
    }


    //printf("%.7lf\n",ans);
    cout << fixed << setprecision(7) << ans + 1 << endl;






    return 0;
}
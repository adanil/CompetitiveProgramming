//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//using ll = long long;
//
//struct prnts{
//    ll bal;
//    ll negPref;
//    ll posPost;
//    ll id;
//};
//
//vector<string> generetedParenthesis;
//
//
//void generateParenthesis(int n,int bal,string prn) {
//    //for (int i = 0;i < n;i++){
//        if (bal > 0 && n > 0){
//            generateParenthesis(n-1,bal+1,prn + '(');
//            generateParenthesis(n,bal-1,prn + ')');
//        }
//        else if (bal > 0 && n == 0){
//            generateParenthesis(n,bal-1,prn + ')');
//        }
//        else if (bal == 0 && n > 0)
//            generateParenthesis(n-1,bal+1,prn + '(');
//        else if (bal == 0 && n == 0)
//            generetedParenthesis.push_back(prn);
//   // }
//}
//
//bool checkParnethesis(string s){
//    ll bres = 0;
//    for (ll i = 0;i < s.size();i++){
//        if (s[i] == '(')
//            bres++;
//        else
//            bres--;
//        if (bres < 0){
//            return false;
//        }
//    }
//    return true;
//}
//
//bool solution(vector<string> vs){
//    vector<prnts> pos;
//    vector<prnts> neg;
//    vector<prnts> zero;
//    for (ll i = 0;i < vs.size();i++){
//        ll posPst = 0;
//        ll bal = 0;
//        ll close = 0;
//        bool fl = true;
//        for (ll j = 0;j < vs[i].size();j++){
//            if (vs[i][j] == '(') {
//                fl = false;
//                bal++;
//                posPst++;
//            }
//            else {
//                bal--;
//                posPst = 0;
//            }
//            if (fl)
//                if (bal < 0)
//                    close = max(close,abs(bal));
//        }
//        if (bal > 0){
//            prnts e;
//            e.bal = bal;
//            e.negPref = close;
//            e.id = i;
//            pos.push_back(e);
//
//        }
//        else if (bal < 0){
//            prnts e;
//            e.bal = bal;
//            e.negPref = close;
//            e.posPost = posPst;
//            e.id = i;
//            neg.push_back(e);
//        }
//        else{
//            prnts e;
//            e.bal = 0;
//            e.negPref = close;
//            e.id = i;
//            zero.push_back(e);
//        }
//    }
//
//    string ans;
//    vector<ll>ansv;
//    sort(pos.begin(),pos.end(),[](prnts a,prnts b){return a.negPref < b.negPref;});
//    ll balance = 0;
//    for (ll i = 0;i < pos.size();i++){
//        if (pos[i].negPref > balance){
////            cout << "NO" << endl;
//            return 0;
//        }
//        ansv.push_back(pos[i].id);
//        ans += vs[pos[i].id];
//        balance += pos[i].bal;
//    }
//
//    for (ll i = 0;i < zero.size();i++){
//        if (zero[i].negPref > balance){
////            cout << "NO" << endl;
//            return 0;
//        }
//        ansv.push_back(zero[i].id);
//        ans += vs[zero[i].id];
//    }
//
//    sort(neg.begin(),neg.end(),[](prnts a,prnts b){return -a.bal + b.negPref < -b.bal + a.negPref;});
//    for (ll i = 0;i < neg.size();i++){
//        if (neg[i].negPref > balance){
////            cout << "NO" << endl;
//            return 0;
//        }
//        ansv.push_back(neg[i].id);
//        ans += vs[neg[i].id];
//        balance += neg[i].bal;
//    }
//    ll bres = 0;
//    for (ll i = 0;i < ans.size();i++){
//        if (ans[i] == '(')
//            bres++;
//        else
//            bres--;
//        if (bres < 0){
////            cout << "NO" << endl;
//            return 0;
//        }
//    }
//    if (bres != 0)
//        return 0;
////        cout << "NO" << endl;
//    else{
////        cout << "YES" << endl;
////        for (auto &el : ansv)
////            cout << el+1 << ' ';
//        return 1;
//        cout << ans << endl;
//    }
//}
//
//
//
//
//
//
//int main() {
//
//    generateParenthesis(10,0,"");
//
////    for (int i = 0;i < generetedParenthesis.size();i++)
////        cout << generetedParenthesis[i] << ' ' << checkParnethesis(generetedParenthesis[i]) << endl;
//
//    vector<vector<string>> slicedPr(generetedParenthesis.size());
//
//    int needSlice = 6;
//
//    for (int i = 0;i < generetedParenthesis.size();i++){
//        int sz = generetedParenthesis[i].size()/needSlice;
//        int pnt = 0;
//        int sliceCount = 0;
//        string slice;
//        for (int j = 0;j < generetedParenthesis[i].size();j++){
//            if (sliceCount < needSlice - 1 && pnt < sz) {
//                slice += generetedParenthesis[i][j];
//                pnt++;
//            }
//            else if (sliceCount < needSlice - 1 && pnt >= sz){
//                slicedPr[i].push_back(slice);
//                sliceCount++;
//                pnt = 1;
//                slice = generetedParenthesis[i][j];
//            }
//            else{
//                slice += generetedParenthesis[i][j];
//                pnt++;
//            }
//
//        }
//        slicedPr[i].push_back(slice);
//    }
//
////    for (int i = 0;i < slicedPr.size();i++){
////        for (auto el : slicedPr[i])
////            cout << el << ' ';
////        cout << endl;
////    }
//
//    for (int i = 0;i < slicedPr.size();i++){
//        cout << "i = " << i << " answer: " << solution(slicedPr[i])<< endl;
//    }
//
//
//    vector<string> wr;
//    wr.push_back("(");
//    wr.push_back("(");
//    wr.push_back("(");
//    wr.push_back(")))((()");
//    wr.push_back("))(");
//    wr.push_back(")");
//
//
//
//
//    cout << solution(wr) << endl;
//
//
////
////    ios_base::sync_with_stdio(false);
////    cin.tie(NULL);
////    ll n;
////    cin >> n;
////    vector<string> vs(n);
////    vector<prnts> pos;
////    vector<prnts> neg;
////    vector<prnts> zero;
////    for (ll i = 0;i < n;i++){
////        ll posPst = 0;
////        cin >> vs[i];
////        ll bal = 0;
////        ll negPr = 0;
//            bool fl = true;
//            for (ll j = 0;j < vs[i].size();j++){
//                if (vs[i][j] == '(') {
//                    fl = false;
//                    bal++;
//                    posPst++;
//                }
//                else {
//                    negPr++;
//                    bal--;
//                    if (posPst > 0) {
//                        posPst--;
//                        negPr--;
//                    }
//
//                }
//            }
////        if (bal > 0){
////            prnts e;
////            e.bal = bal;
////            e.negPref = close;
////            e.id = i;
////            pos.push_back(e);
////
////        }
////        else if (bal < 0){
////            prnts e;
////            e.bal = bal;
////            e.negPref = close;
////            e.posPost = posPst;
////            e.id = i;
////            neg.push_back(e);
////        }
////        else{
////            prnts e;
////            e.bal = 0;
////            e.negPref = close;
////            e.id = i;
////            zero.push_back(e);
////        }
////    }
////
////    string ans;
////    vector<ll>ansv;
////    sort(pos.begin(),pos.end(),[](prnts a,prnts b){return a.negPref < b.negPref;});
////    ll balance = 0;
////    for (ll i = 0;i < pos.size();i++){
////        if (pos[i].negPref > balance){
////            cout << "NO" << endl;
////            return 0;
////        }
////        ansv.push_back(pos[i].id);
////        ans += vs[pos[i].id];
////        balance += pos[i].bal;
////    }
////
////    for (ll i = 0;i < zero.size();i++){
////        if (zero[i].negPref > balance){
////            cout << "NO" << endl;
////            return 0;
////        }
////        ansv.push_back(zero[i].id);
////        ans += vs[zero[i].id];
////    }
////
////    sort(neg.begin(),neg.end(),[](prnts a,prnts b){return a.posPost > b.posPost;});
////    for (ll i = 0;i < neg.size();i++){
////        if (neg[i].negPref > balance){
////            cout << "NO" << endl;
////            return 0;
////        }
////        ansv.push_back(neg[i].id);
////        ans += vs[neg[i].id];
////        balance += neg[i].bal;
////    }
////    ll bres = 0;
////    for (ll i = 0;i < ans.size();i++){
////        if (ans[i] == '(')
////            bres++;
////        else
////            bres--;
////        if (bres < 0){
////            cout << "NO" << endl;
////            return 0;
////        }
////    }
////    if (bres != 0)
////        cout << "NO" << endl;
////    else{
////        cout << "YES" << endl;
////        for (auto &el : ansv)
////            cout << el+1 << ' ';
//////        cout << ans << endl;
////    }
//
//    return 0;
//}







/////


//
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//namespace Danil {
//    using namespace std;
//    using ll = long long;
//
//    struct prnts{
//        ll bal;
//        ll negPref;
//        ll posPost;
//        ll id;
//    };
//
    std::string main(const vector<string>& vs) {
        const int n = (int)vs.size();
        //cin >> n;
        //vector<string> vs(n);
        vector<prnts> pos;
        vector<prnts> neg;
        vector<prnts> zero;
        for (ll i = 0;i < n;i++){
            ll posPst = 0;
            //cin >> vs[i];
            ll bal = 0;
            ll negPr = 0;
            bool fl = true;
            for (ll j = 0;j < vs[i].size();j++){
                if (vs[i][j] == '(') {
                    fl = false;
                    bal++;
                    posPst++;
                }
                else {
                    negPr++;
                    bal--;
                    if (posPst > 0) {
                        posPst--;
                        negPr--;
                    }

                }
            }
            if (bal > 0){
                prnts e;
                e.bal = bal;
                e.negPref = negPr;
                e.id = i;
                pos.push_back(e);

            }
            else if (bal < 0){
                prnts e;
                e.bal = bal;
                e.negPref = negPr;
                e.posPost = posPst;
                e.id = i;
                neg.push_back(e);
            }
            else{
                prnts e;
                e.bal = 0;
                e.negPref = negPr;
                e.id = i;
                zero.push_back(e);
            }
        }

        string ans;
        vector<ll>ansv;
        sort(pos.begin(),pos.end(),[](prnts a,prnts b){return a.negPref < b.negPref;});
        ll balance = 0;
        for (ll i = 0;i < pos.size();i++){
            if (pos[i].negPref > balance){
                return "NO";//cout << "NO" << endl;
                //return 0;
            }
            ansv.push_back(pos[i].id);
            ans += vs[pos[i].id];
            balance += pos[i].bal;
        }

        for (ll i = 0;i < zero.size();i++){
            if (zero[i].negPref > balance){
                return "NO"; //cout << "NO" << endl;
                //return 0;
            }
            ansv.push_back(zero[i].id);
            ans += vs[zero[i].id];
        }

        sort(neg.begin(),neg.end(),[](prnts a,prnts b){return  a.posPost >  b.posPost;});
        for (ll i = 0;i < neg.size();i++){
            if (neg[i].negPref > balance){
                return "NO";//cout << "NO" << endl;
                //return 0;
            }
            ansv.push_back(neg[i].id);
            ans += vs[neg[i].id];
            balance += neg[i].bal;
        }
        ll bres = 0;
        for (ll i = 0;i < ans.size();i++){
            if (ans[i] == '(')
                bres++;
            else
                bres--;
            if (bres < 0){
                return "NO";//cout << "NO" << endl;
                //return 0;
            }
        }
        if (bres != 0)
            return "NO";//cout << "NO" << endl;
        else{
            return "YES";//cout << "YES" << endl;

            //for (auto &el : ansv)
            //    cout << el+1 << ' ';
            //        cout << ans << endl;
        }
    }
}

std::string next(std::string s) {
    int n = (int) s.length();
    std::string ans = "-1";
    for (int i=n-1, depth=0; i>=0; --i) {
        if (s[i] == '(')
            --depth;
        else
            ++depth;
        if (s[i] == '(' && depth > 0) {
            --depth;
            int open = (n-i-1 - depth) / 2;
            int close = n-i-1 - open;
            ans = s.substr(0,i) + ')' + std::string (open, '(') + std::string (close, ')');
            break;
        }
    }
    //assert(ans != "-1");
    return ans;
}
int main() {
    for (int n = 1; n <= 10; n++) {
        std::string seq = std::string(n, '(') + std::string(n, ')');
        while (seq != "-1") {
            std::vector<std::string> vs;
            for (int i = 1; i < 2 * n; i++) {
                vs.push_back(seq.substr(0,i));
                for (int j = i+1; j < 2 * n; j++) {
                    vs.push_back(seq.substr(i,j-i));
                    for (int k = j+1; k < 2 * n; k++) {
                        vs.push_back(seq.substr(j,k-j));
                        for (int t = k+1; t < 2 * n; t++) {
                            vs.push_back(seq.substr(k,t-k));
                            for (int r = t+1; r < 2 * n; r++) {
                                vs.push_back(seq.substr(t,r-t));
                                vs.push_back(seq.substr(r,2*n-r));
                                auto copy = vs;
#define all(x) (x).begin(),(x).end()
                                std::sort(all(copy));
                                if (Danil::main(vs) == "NO") {
                                    std::cout << vs.size() << std::endl;
                                    for (auto &it : vs) {
                                        std::cout << it << std::endl;
                                    }
                                    for (auto el: vs){
                                        std::cout << el << ' ';
                                    }
                                    std::cout << "Wrong" << std::endl;
                                    std::exit(0);
                                }
                                vs.pop_back();
                                vs.pop_back();
                            }
                            vs.pop_back();
                        }
                        vs.pop_back();
                    }
                    vs.pop_back();
                }
                vs.pop_back();
            }
            std::cerr << "seq=" << seq << ": OK" << '\n';
            seq = next(seq);
        }
    }
}
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int Q;
    cin >> Q;
    unordered_set<string> A, B;
    unordered_multiset<string> prefix, postfix;
    for(int i=0;i<Q;i++){
        string q; cin >> q;
        if(q == "add"){
            string set_name, S;
            cin >> set_name >> S;
            if(set_name == "A"){
                if(A.count(S)){
                    continue;
                }
                A.insert(S);
                for(int len=1;len<=S.size();len++){
                    prefix.insert(S.substr(0, len));
                }
            }else{
                if(B.count(S)){
                    continue;
                }
                B.insert(S);
                for(int len=1;len<=S.size();len++){
                    postfix.insert(S.substr(S.size()-len, len));
                }
            }
        }else if (q == "delete"){
            string set_name, S;
            cin >> set_name >> S;
            if(set_name == "A"){
                A.erase(S);
                for(int len=S.size();0<len;len--){
                    prefix.erase(prefix.find(S.substr(0, len)));
                }
            }else{
                B.erase(S);
                for(int len=S.size();0<len;len--){
                    postfix.erase(postfix.find(S.substr(S.size()-len, len)));
                }
            }
        }else{
            string S; cin >> S;
            int cnt = 0;
            for(int len=1;len<S.size();len++){
                cnt += prefix.count(S.substr(0,len)) * postfix.count(S.substr(len,S.size()-len));
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}     
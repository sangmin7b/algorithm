#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(){
    int Q, K; cin >> Q >> K;
    int temp = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(Q--){
        string s; cin >> s;
        if(s == "insert"){
            int x; cin >> x;
            temp ^= x;
            pq.push(x);
            if(K < pq.size()){
                temp ^= pq.top();
                pq.pop();
            }
        }else{
            cout << temp << "\n";
        }
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     
#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;

void solve(){
    ll N; cin >> N;
    int cnt = 0;
    for(ll k=2;k*k <= 2*N;k++){
        if(k % 2 == 0){
            if(N % k != 0 && (2 * N) % k == 0)
                cnt++;
        }else{
            if(N % k == 0)
                cnt++;
        }
    }
    cout << cnt << "\n";
}

int main(int argc, const char** argv) {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
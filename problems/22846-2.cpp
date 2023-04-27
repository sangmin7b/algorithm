#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int K;
vvi dp(2, vi(100000,-1));

int check(int n, int turn){
    if(K <= n){
        return turn^1;
    }
    if(dp[turn][n] != -1){
        return dp[turn][n];
    }
    for(int j=1;j*j<=n;j++){
        if(n % j != 0){
            continue;
        }
        if(check(n+j, turn^1) == turn){
            dp[turn][n] = turn;
            return turn;
        }
        int j2 = n / j;
        if(check(n+j2, turn^1) == turn){
            dp[turn][n] = turn;
            return turn;
        }
    }
    dp[turn][n] = turn^1;
    return turn^1;
}

int main(int argc, const char** argv) {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    string players[2] = {"Kali", "Ringo"};
    cin >> K;
    cout << players[check(1, 0)];
    //cout << players[check(1, 1)];
    /*  
    for(int i=0;i<K;i++){
        cout << "K: " << K << " ";
        cout << "dp[0]["<<i<<"]" << dp[0][i] << " ";
        cout << "dp[1]["<<i<<"]" << dp[1][i] << "\n";
    }
    */
    return 0;
}     
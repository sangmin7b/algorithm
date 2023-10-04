#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int M = 1e5;
ll N, a, b, c;

int next(int x){
    return c * (x + b) % M;
}

int pow_n(ll x, int n){
    ll ans = 1;
    while(n--){
        ans *= x;
        ans %= M;
    }
    return ans;
}

int dp[15][100000][15];

ll solve(int step, ll acc, ll cont){
    if(step == N){
        return acc * pow_n(c, cont) % M;
    }
    if(dp[step][acc][cont] != -1){
        return dp[step][acc][cont];
    }
    ll ans = max(solve(step+1, (acc+b) % M, cont+1), solve(step+1, next(acc), cont));
    if(cont){
        ans = max(ans, solve(step, c * acc % M, cont - 1));
    }
    dp[step][acc][cont] = ans;
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> a >> b >> c;
    for(int i=0;i<15;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<15;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << solve(0, a, 0);
    return 0;
}     
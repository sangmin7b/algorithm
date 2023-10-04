#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

ll MOD = 1e9 + 7;

ll dp[51];
ll factorial[61];
ll inv_factorial[61];

ll _pow(ll x, ll k){
    ll res = 1;
    while(k){
        if(k & 1){
            res *= x; res %= MOD;
        }
        x *= x; x %= MOD;
        k = k >> 1;
    }
    return res;
}

ll choose(ll n, ll k){
    ll res = factorial[n] * inv_factorial[k] % MOD;
    res *= inv_factorial[n-k]; res %= MOD;
    return res;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x = 1;
    factorial[0] = 1;
    inv_factorial[0] = 1;
    for(int i = 1; i <= 60; i++){
        x *= i; x %= MOD;
        factorial[i] = x;
        inv_factorial[i] = _pow(x, MOD - 2);    
    }
    ll N, K; cin >> N >> K;
    dp[0] = N;
    dp[1] = (N * (N + 1) / 2) % MOD;     
    for(int i = 2; i <= 50; i++){
        dp[i] = _pow(N, i + 1);
        for(int j = 2; j <= i + 1; j++){
            ll s = j % 2 ? -1 : 1;
            dp[i] += s * choose(i + 1, j) * dp[i + 1 - j] % MOD;
            dp[i] %= MOD;
        }
        dp[i] *= _pow(i + 1, MOD - 2); dp[i] %= MOD;       
        dp[i] = (dp[i] + MOD) % MOD; 
    }
    cout << dp[K];
    return 0;
}     
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int MOD = 1e9 + 7;

ll inv(ll x){
    int p2 = MOD - 2;
    ll res = 1;
    while(p2){
        if(p2 & 1){
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        p2 = p2 >> 1;
    }
    return res;
}

int choice(int r, int c){
    ll res = 1;
    for(int i=r-c+1;i<=r;i++){
        res *= i;
        res %= MOD;
    }
    for(int i=2;i<=c;i++){
        res *= inv(i);
        res %= MOD;
    }
    return res;
}

int main(int argc, const char** argv) {
    int N; cin >> N;
    vi nums(3,0);
    for(int &x: nums){
        cin >> x;
    }
    sort(nums.begin(), nums.end());
    if(accumulate(nums.begin(), nums.end(), 0) < N){
        cout << 0 << "\n";
        return 0;
    }
    vl dp(51, 0);
    for(int i=nums[2];i<=N;i++){
        ll c = 1;
        for(int j=0;j<3;j++){
            c *= choice(i, nums[j]);
            c %= MOD;
        }
        dp[i] = c;
        for(int j=1;j<i;j++){
            dp[i] = (dp[i] - ((choice(i, j) * dp[j]) % MOD) + MOD) % MOD;
        }
    }
    cout << dp[N] << "\n";
    return 0;
}     
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vvl dp(31, vl(31, -1));

ll f(int N, int K){
    if(K < 0){
        return 0;
    }
    if(N == 0){
        return 1;
    }
    if(dp[N][K] != -1){
        return dp[N][K];
    }
    dp[N][K] = f(N-1, K+1) + f(N, K-1);
    return dp[N][K];
}

void solve(int N){
    cout << f(N, 0) << "\n";
    return;
}

int main(int argc, const char** argv) {
    while(1){
        int N; cin >> N;
        if(N == 0)
            break;
        solve(N);
    }
    return 0;
}
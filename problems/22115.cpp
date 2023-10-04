#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vi nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    vi dp(K+1, 1e9);
    dp[0] = 0;
    for(int i=0;i<N;i++){
        for(int x=K;nums[i]<x;x--){
            dp[x] = min(dp[x], dp[x-nums[i]] + 1);
        }
        dp[nums[i]] = 1;
    }
    if(dp[K] != 1e9){
        cout << dp[K];
    }else{
        cout << -1;
    }
    return 0;
}
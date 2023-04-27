#include<bits/stdc++.h>
using namespace std;
int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vector<vector<int>> cost(N,vector<int>(3,0));
    vector<vector<int>> dp(N,vector<int>(3,-1));

    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> cost[i][j];
        }
    }
    dp[0][0] = cost[0][0]; 
    dp[0][1] = cost[0][1]; 
    dp[0][2] = cost[0][2]; 
    for(int i=1;i<N;i++){
        for(int color =0;color<3;color++){
            dp[i][color] = min(dp[i-1][(color+1)%3], dp[i-1][(color+2)%3]) + cost[i][color];
        }
    }
    int ans = min(min(dp[N-1][0],dp[N-1][1]),dp[N-1][2]);
    cout << ans;
    return 0;
}
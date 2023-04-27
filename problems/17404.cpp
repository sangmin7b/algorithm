#include<bits/stdc++.h>
int INF = 2e9;
using namespace std;
using pii = pair<int,int>;
int main(int argc, const char** argv) {
    
    int N;
    cin >> N;

    vector<vector<int>> cost = vector<vector<int>>(N, vector<int>(3));
    vector<vector<int>> dp = vector<vector<int>>(N, vector<int>(3));

    for(int i=0;i<N;i++){
        int r, g, b;
        cin >> r >> g >> b;
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    int ans = INF;

    for(int i=0;i<3;i++){
         dp = vector<vector<int>>(N, vector<int>(3));
        dp[0][0] = INF;         
        dp[0][1] = INF;         
        dp[0][2] = INF;
        dp[0][i] = cost[0][i];         
    
        for(int i=1;i<N;i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }
        
        for(int j=0;j<3;j++){
            if(j != i){
                ans = min(dp[N-1][j], ans);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
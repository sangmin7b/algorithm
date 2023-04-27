#include<bits/stdc++.h>
using namespace std;

int dp[20][301];
int profit[20][301];
int invested[20][301];

int main(int argc, char const *argv[]){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int v; cin >> v;
        for(int j=0;j<M;j++){
            int p; cin >> p;
            profit[j][v] = p;
        }
    }

    int m = profit[0][1];
    int inv = 1;
    for(int i=1;i<=N;i++){
        if (m < profit[0][i] ){
            m = profit[0][i];
            inv = i;
        }
        invested[0][i] = inv;
        dp[0][i] = m;
    }

    for(int i=1;i<M;i++){
        for(int j=1;j<=N;j++){
            int m = profit[i][j];
            int inv = j;
            for(int k=0;k<=j;k++){
                if (m < dp[i-1][k] + profit[i][j-k]){
                    m = dp[i-1][k] + profit[i][j-k];
                    inv = j - k;
                }                
            }
            invested[i][j] = inv;
            dp[i][j] = m;
        }
    }
    cout << dp[M-1][N] << "\n";
    int remaining = N;
    vector<int> ans;
    for(int i=M-1;i>=0;i--){
        ans.push_back(invested[i][remaining]);
        remaining -= invested[i][remaining];
    }
    for(int i=0;i<M;i++){
        cout << ans[M - 1 -i] << " ";
    }

    return 0;
}

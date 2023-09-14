#include<bits/stdc++.h>
#define SZ 100002

using namespace std;

int nums[SZ], dist[26][26], psum[26][SZ], dp[26][SZ]; 

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    string s; cin >> s;
    for(int i = 0; i < N; i++){
        nums[i] = s[i] - 'a';
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cin >> dist[i][j];
        }
    }
    for(int k = 0; k < M; k++){
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            psum[i][j + 1] = psum[i][j] + dist[nums[j]][i];
        }
    }      
    for(int j = K - 1; j < N; j++){
        for(int i = 0; i < M; i++){
            if(j < 2 * K - 1){
                dp[i][j] = psum[i][j+1];
                continue;
            }
            int t = dp[i][j-1] + dist[nums[j]][i];
            for(int k = 0; k < M; k++){
                t = min(t, dp[k][j-K] + psum[i][j+1] - psum[i][j+1-K]);            
            }
            dp[i][j] = t;
        }
    }
    int ans = 1e9;
    for(int i = 0; i < M; i++){
        ans = min(ans, dp[i][N-1]);
    }
    cout << ans;
    return 0;
}     
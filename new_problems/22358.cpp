#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vector<vector<pi>> adj;
vector<vector<pi>> rev_adj;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;
    vvl dp(N + 1, vl(K, 0));
    adj = vector<vector<pi>>(N + 1);
    rev_adj = vector<vector<pi>>(N + 1);
    for(int i = 0; i < M; i++){
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back({b, t});
        rev_adj[b].push_back({a, t});
    }
    vi visited(N + 1, 0);
    visited[T] = 1;
    for(int i = T; 0 < i; i--){
        for(auto[next, t] : rev_adj[i]){
            if(visited[i]){
                dp[next][0] = max(dp[next][0], dp[i][0] + t);
                visited[next] = 1;
            }            
        }
    }
    for(int k = 1; k <= K; k++){
        for(int i = N; 0 < i; i--){
            dp[i][k] = dp[i][k-1];
            for(auto[next, t] : rev_adj[i]){
                dp[i][k] = max(dp[i][k], dp[next][k - 1]);
                if(next == T || visited[next]){
                    visited[i] = 1;
                }
            }
            for(auto[next, t] : adj[i]){
                if(dp[next][k] || visited[next]){
                    dp[i][k] = max(dp[i][k], dp[next][k] + t);
                }
            }
        }
    }
    if(dp[S][K]){
        cout << dp[S][K];
    }else{
        if(visited[S]){
            cout << 0;
        }else{
            cout << -1;
        }
    }
    return 0;
}     
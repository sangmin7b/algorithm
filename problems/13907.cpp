#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    int S, D; cin >> S >> D;
    vector<vector<pi>> adj(N + 1);
    for(int i = 0; i < M; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vvi dist(N + 1, vi(N + 1, 1e9));
    dist[0][S] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(auto p : adj[j]){
                dist[i][p.first] = min(dist[i][p.first], dist[i-1][j] + p.second);
            }
        }        
    }
    int tax = 0;
    for(int i = 0; i <= K; i++){
        if(i != 0){
            int t; cin >> t;
            tax += t;
        }
        int ans = 1e9;
        for(int j = 0; j <= N; j++){
            ans = min(ans, dist[j][D] + j * tax);
        }
        cout << ans << "\n";
    }
    return 0;
}     
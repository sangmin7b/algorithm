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
    int V, E; cin >> V >> E;
    vector<vector<int>> dist(V + 1, vector<int>(V + 1, 1e9));
    for(int i = 0; i < E; i++){
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= V; i++){
        ans = min(ans, dist[i][i]);
    }
    if(ans == 1e9){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}     
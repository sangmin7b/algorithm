#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, M;
vvi adj;
vvi dist;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    adj = vvi(N);
    dist = vvi(N, vi(N, 1e9));
    for(int i = 0; i< N; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    pi ans = {0, 0};
    int min_sum = 2e9;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            int sum = 0;
            for(int k = 0; k < N; k++){
                sum += min(dist[i][k], dist[j][k]);
            }
            if(sum < min_sum){
                min_sum = sum;
                ans = {i + 1, j + 1};
            }
        }
    }
    cout << ans.first << " " << ans.second << " " << 2 * min_sum;
    return 0;
}     
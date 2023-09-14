#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N;
vi color;
vi visited;
vvi adj;

int dfs(int x){
    visited[x] = 1;
    int cnt = 0;
    for(int next : adj[x]){
        if(!visited[next]){
            if(color[next] != color[x]){
                cnt++;
            }
            cnt += dfs(next);
        }
    }
    return cnt;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    color = vi(N);
    adj = vvi(N);
    for(auto &x : color) cin >> x;
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited = vi(N, 0);
    int ans = dfs(0);
    if(color[0]) ans++;
    cout << ans;    
    return 0;
}     
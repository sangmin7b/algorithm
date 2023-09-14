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
    vi degree(V);
    vvi adj(V, vi(V));
    for(int i = 0; i < E; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        degree[a]++; degree[b]++;
        adj[a][b] = 1; adj[b][a] = 1;
    }
    vi visited(V);
    int component = 0;
    int component_c = 0;
    int ans = 0;
    for(int i = 0; i < V; i++){
        if(visited[i]) continue;
        int cnt = 0;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(degree[x] % 2) cnt++;
            for(int next = 0; next < V; next++){
                if(!adj[x][next] || visited[next]) continue;
                visited[next] = 1;
                q.push(next);
            }
        }
        component++;
        ans += max(0, cnt - 2) / 2;   
    }
    if(1 < component){
        ans += component - 1;
    }
    cout << ans;
    return 0;
}     
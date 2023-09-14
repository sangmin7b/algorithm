#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(int T){
    int N, R; cin >> N >> R;
    vvi adj(N, vi(N, 0));
    vi degree(N, 0);
    for(int i = 0; i < R; i++){
        int a, b; cin >> a >> b;
        adj[a][b]++; adj[b][a]++;
        degree[a]++; degree[b]++;
    }
    int ans = 0;
    int component = 0;
    int component2 = 0;
    vi visited(N, 0);
    for(int i = 0; i < N; i++){
        if(visited[i] || !degree[i]) continue;
        visited[i] = 1;
        queue<int> q;
        q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            cnt += degree[x] & 1;
            for(int next = 0; next < N; next++){
                if(!adj[x][next] || visited[next]) continue;
                visited[next] = 1;
                q.push(next);                
            }
        }
        if(cnt)
            component2++;
        component++;
        ans += cnt / 2;
    }
    if(1 < component)
        ans += component - component2;
    cout << "Case #" << T << ": " << ans << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
    return 0;
}
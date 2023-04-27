#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

void solve(){
    int V, E;
    cin >> V >> E;
    vvi adj(V,vi());
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi visited(V,0);
    function<bool(int)> bfs = [&](int x){
        queue<int> q;
        q.push(x);
        visited[x] = 1;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            int c = 1;
            if(visited[now] == 1){
                c = 2;
            }
            for(int next: adj[now]){
                if(visited[next] == c)
                    continue;
                if(visited[next] == 0){
                    visited[next] = c;
                    q.push(next);
                    continue;
                }
                return false;
            }            
        }
        return true;
    };
    bool ans = true;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            ans = ans & bfs(i);
        }
    }
    if(ans){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
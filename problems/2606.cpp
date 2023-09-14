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
    int N, M; cin >> N >> M;
    vvi adj(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        a--; b--;  
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    vi visited(N);
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int next: adj[x]){
            if(visited[next]) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
    cout << accumulate(visited.begin(), visited.end(), 0) - 1;
    return 0;
}     
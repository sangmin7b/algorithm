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
vi depth;
vvi parent;

int nth_parent(int a, int n){
    for(int i=0;i<32;i++){
        if(n & (1 << i)){
            a = parent[a][i];
        }
    }
    return a;
}

int lca(int a, int b){
    if(depth[a] < depth[b]){
        return lca(b, a);
    }    
    a = nth_parent(a, depth[a] - depth[b]);
    int h = 0;
    for(int i=0;i<32;i++){
        if(depth[a] & (1 << i)){
            h = i;
        }
    }
    if(a == b){
        return a;
    }
    int ans = a;
    for(int i=h;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
        ans = parent[a][i];
    }
    return ans;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    adj = vvi(N);
    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent = vvi(N, vi(32, 0));
    depth = vi(N, 0);
    queue<int> q;
    vi visited(N, 0);
    visited[0] = 1;
    q.push(0);
    parent[0][0] = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int child: adj[x]){
            if(visited[child])
                continue;
            visited[child] = 1;
            parent[child][0] = x;
            depth[child] = depth[x] + 1;
            q.push(child);            
        }
    }
    for(int i=1;i<17;i++){
        for(int j=0;j<N;j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << lca(a, b) + 1 << "\n";
    }
    return 0;
}     
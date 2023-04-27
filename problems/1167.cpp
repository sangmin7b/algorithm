#include<bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

struct edge{
    int to;
    int w;
};
vi visited;
vector<vector<edge>> adj;

pii dfs(int x){
    vi dists{0, 0};
    int width = 0;
    for(edge e: adj[x]){
        if(visited[e.to])
            continue;
        visited[e.to] = 1;
        pii r = dfs(e.to);
        dists.push_back(e.w + r.first);
        width = max(width, r.second);
    }
    sort(dists.begin(), dists.end(), greater<int>());
    width = max(width, dists[0] + dists[1]);
    return {dists[0], width};
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int V;
    cin >> V;
    visited = vi(V,0);
    adj = vector<vector<edge>>(V);
    for(int i=0;i<V;i++){
        int x; cin >> x;
        x--;
        while(1){
            int to, w;
            cin >> to;
            if(to == -1)
                break;
            to--;
            cin >> w;
            adj[x].push_back({to, w});
        }
    }

    visited[0] = 1;
    cout << dfs(0).second;
    return 0;
}
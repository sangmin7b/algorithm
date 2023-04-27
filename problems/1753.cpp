#include<bits/stdc++.h>
#include <functional>

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

const int inf = 1e9;
vector<vector<pi>> adj;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int V, E; cin >> V >> E;
    int K; cin >> K;
    adj = vector<vector<pi>>(V+1);
    for(int i=0;i<E;i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vi dist(V+1, inf);
    dist[K] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, K});
    while(!pq.empty()){
        auto [d, x] = pq.top(); 
        pq.pop();
        if(dist[x] < d){
            continue;
        }
        for(pi p: adj[x]){
            auto [next, w] = p;
            if(dist[x] + w < dist[next]){
                dist[next] = dist[x] + w;
                pq.push({dist[x] + w, next});
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(dist[i] == inf){
            cout << "INF\n";
        }else{
            cout << dist[i] << "\n";
        }
    }
    return 0;
}     
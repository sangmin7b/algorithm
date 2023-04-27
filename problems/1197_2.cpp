/*
    Prim algorithm
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

bool visited [10000];

int main(int argc, const char** argv) {
    int V, E;
    cin >> V >> E;
    priority_queue<pii> pq;
    vector<pii> adj[V];    
    int sum = 0;
    for(int i=0;i<E;i++){
        int from, to, w;
        cin >> from >> to >> w;
        from--; to--;
        adj[from].push_back({w,to});
        adj[to].push_back({w,from});
    }
    for(int i=0;i<V;i++){
        visited[i] = 0 ;
    }
    for(pii next: adj[0]){
        pq.push({-next.first, next.second});
    }

    int edges = 0;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int weight = -node.first;
        if(visited[node.second]) continue;

        sum += weight;
        visited[node.second] = true;
        for(auto next: adj[node.second]){
            pq.push({-next.first, next.second});
        }

        if(edges == V - 1){
            break;
        }
    }
    cout << sum;

    return 0;
}
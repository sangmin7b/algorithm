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
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pl>> adj(2 * N);       
    for(int i = 0; i < M; i++){
        int from, to, w; cin >> from >> to >> w;
        from--, to--;
        adj[from].push_back({to, w});
    }
    vi is_starting_point(2 * N , 0);
    for(int i = 0; i < K; i++){
        int s; cin >> s;
        int now; cin >> now; now--;
        is_starting_point[now] = 1;
        int next;
        for(int j = 1; j < s; j++){
            cin >> next; next--;
            queue<pl> q;
            for(auto edge : adj[now]){
                if(edge.first == next){
                    if(j < s - 1){
                        q.push({next + N, edge.second});    
                    }
                }else{
                    q.push(edge);    
                }
            }
            while(!q.empty()){
                adj[now + N].push_back(q.front());
                q.pop();
            }
            now = next;
        }
    }
    for(int i = 0; i < 2 * N; i++){
        for(int j = 0; j < adj[i].size(); j++){
            queue<pl> q;
            if(is_starting_point[adj[i][j].first]){
                q.push({adj[i][j].first + N, adj[i][j].second});
                adj[i][j].second = 1e18;
            }
            while(!q.empty()){
                adj[i].push_back(q.front());
                q.pop();
            }
        }
    }
    vl dist(2 * N, 1e18);
    vi visited(2 * N);
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    if(is_starting_point[0]){
        dist[N] = 0;
        pq.push({0, N});
    }else{
        dist[0] = 0;
        pq.push({0, 0});        
    }
    while(!pq.empty()){
        auto [d, now] = pq.top(); pq.pop();
        if(visited[now]) continue;
        visited[now] = 1;
        for(auto edge : adj[now]){
            if(d + edge.second < dist[edge.first]){
                dist[edge.first] = d + edge.second;
                pq.push({d + edge.second, edge.first});
            }
        }
    }
    for(int i = 0; i < N; i++){
        ll d = min(dist[i], dist[i + N]);
        if(d != 1e18){
            cout << d << " ";
        }else{
            cout << -1 << " ";
        }
    }
    return 0;
}     
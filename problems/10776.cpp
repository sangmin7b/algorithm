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
    int K, N, M;
    cin >> K >> N >> M;
    vector<vector<tuple<int, int, int>>> adj(N+1);
    for(int i=0;i<M;i++){
        int A, B, t, h;
        cin >> A >> B >> t >> h;
        adj[A].push_back({B, t, h});
        adj[B].push_back({A, t, h});
    }
    vi prev(N+1);    
    iota(prev.begin(), prev.end(),0);
    vector<vector<int>> dist(N+1, vi(200, 1e9));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    int A, B; cin >> A >> B;
    pq.push({0, 0, A});
    while(!pq.empty()){
        auto[t, h, node] = pq.top(); pq.pop();
        if(dist[node][h] <= t){
            continue;
        }
        dist[node][h] = t;
        for(auto [next_node, next_t, next_h]: adj[node]){
            if(K <= h + next_h){
                continue;
            }
            if(dist[next_node][h+next_h] <= t + next_t){
                continue;
            }
            pq.push({next_t + t, next_h + h, next_node});
        }
    }
    int ans = *min_element(dist[B].begin(), dist[B].end());
    if(ans != 1e9){
        cout << ans;
     }else{
       cout << -1;
    }
    return 0;
}     
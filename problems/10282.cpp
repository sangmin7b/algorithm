#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve(){
    int N, d, c;
    cin >> N >> d >> c;
    c--;
    vector<vector<pi>> adj(N);
    vi visited(N, 0);
    vi dist(N, 0);
    for(int i=0;i<d;i++){
        int a, b, s; cin >> a >> b >> s;
        a--; b--;
        adj[b].push_back({a, s});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, c});
    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();
        if(visited[p.second]){continue;}        
        dist[p.second] = p.first;
        visited[p.second] = 1;
        for(pi edge: adj[p.second]){
            if(visited[edge.first]){
                continue;
            }
            pq.push({p.first + edge.second, edge.first});
        }    
    }
    int cnt = accumulate(visited.begin(), visited.end(), 0);
    int t = *max_element(dist.begin(), dist.end());
    cout << cnt << " " << t << "\n";
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
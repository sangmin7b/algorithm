#include<bits/stdc++.h>
#define all(x) (x.begin(), x.end())
#define rall(x) (x.rbegin(), x.rend())

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

struct edge{
    int to;
    int w;
};
int N, P, K;
const int inf = 987654321;
vector<vector<edge>> adj;

int shortest_path(int threshold){
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    vi dist(N, inf);
    while(!pq.empty()){
        int d, now;
        tie(d, now) = pq.top();
        pq.pop();
        for(edge x: adj[now]){
            int w = 0;
            if(threshold < x.w)
                w = 1;
            if((dist[x.to] <= d + w))
                continue;
            dist[x.to] = d + w;
            pq.push({d+w, x.to});
        }
    }
    return dist[N-1];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> P >> K;
    adj = vector<vector<edge>>(N, vector<edge>());
    for(int i=0;i<P;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int lo = 0;
    int hi = 1000001;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(shortest_path(mid) <= K){
            hi = mid;
        }else{  
            lo = mid + 1;
        }   
    }
    if(lo == 1000001)
        cout << -1;
    else
        cout << lo;
    return 0;
}
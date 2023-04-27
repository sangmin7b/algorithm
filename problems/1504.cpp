#include<bits/stdc++.h>
#include <functional>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vector<vector<pi>> adj;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, E;
    cin >> N >> E;
    adj = vector<vector<pi>>(N+1);
    for(int i=0;i<E;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int m1, m2; cin >> m1 >> m2;
    int dist_1[2];
    int dist_N[2];
    int dist_m1m2;
    vi dist = vi(N+1, 1e9);    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[m1] = 0;
    pq.push({0,m1});
    while(!pq.empty()){
        auto [d, x] = pq.top();
        pq.pop();
        for(pi p: adj[x]){
            auto [next, w] = p;
            if(d + w < dist[next]){
                dist[next] = d + w;
                pq.push({dist[next], next});
            }
        }
    }
    dist_1[0] = dist[1];
    dist_N[0] = dist[N];
    dist_m1m2 = dist[m2];
    dist = vi(N+1, 1e9);   
    dist[m2] = 0;
    pq.push({0,m2});
    while(!pq.empty()){
        auto [d, x] = pq.top();
        pq.pop();
        for(pi p: adj[x]){
            auto [next, w] = p;
            if(d + w < dist[next]){
                dist[next] = d + w;
                pq.push({dist[next], next});
            }
        }
    }
    dist_1[1] = dist[1];
    dist_N[1] = dist[N];
    ll ans = (ll)min(dist_1[0] + dist_N[1], dist_1[1] + dist_N[0]) + dist_m1m2;
    if(1e9 <= ans){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}     
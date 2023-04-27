#include<bits/stdc++.h>
#define SZ 100001

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int parent[SZ];
int dsu_size[SZ];
int N, M;
unordered_map<ll, pi> ans;
vector<vector<pi>> queries;

ll key(pi p){
    return (ll)p.first << 32 | p.second;
}

struct edge{
    int x; 
    int y;
    int w;
    bool operator < (const edge& b) const {
        return w > b.w;
    }
};

int dsu_find(int x){
    if(parent[x] != x){
        parent[x] = dsu_find(parent[x]);
    }
    return parent[x];
}

void dsu_union(edge e){
    auto [x, y, w] = e;
    int px = dsu_find(x);
    int py = dsu_find(y);
    if(px == py){
        return;
    }
    if(dsu_size[px] < dsu_size[py]){
        swap(px, py);
    }    
    for(pi p: queries[py]){
        if(dsu_find(p.second) == px){
            ans.insert({key({min(p.first,p.second), max(p.first,p.second)}), {w, dsu_size[px]+dsu_size[py]}});
        }else{
            queries[px].push_back(p);
        }
    }
    parent[py] = px;
    dsu_size[px] += dsu_size[py];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }
    priority_queue<edge> edges;
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push({a,b,c});
        edges.push({b,a,c});
    }
    queries = vector<vector<pi>>(N+1);
    queue<pi> q;
    int Q; cin >> Q;
    for(int i=0;i<Q;i++){
        int x, y;
        cin >> x >> y;
        queries[x].push_back({x,y});
        queries[y].push_back({y,x});
        q.push({x,y});
    }
    int cnt = 0;
    while(cnt < N-1 && !edges.empty()){
        edge e = edges.top();
        edges.pop();
        int x = e.x;
        int y = e.y;
        if(dsu_find(x) == dsu_find(y)){
            continue;
        }
        dsu_union(e);
        cnt++;
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(y < x){
            swap(x, y);
        }
        auto it = ans.find(key({x,y}));
        if(it == ans.end()){
            cout << -1 << "\n";
        }else{
            cout << (it->second.first) << " " << it->second.second << "\n";
        }
    }
    return 0;
}     
#include<bits/stdc++.h>
#define SZ 2048

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int dsu_size[SZ];
int parent[SZ];

int dsu_find(int x){
    if(parent[x] != x){
        parent[x] = dsu_find(parent[x]);
    }
    return parent[x];
}

bool dsu_union(int x, int y){
    int px = dsu_find(x);
    int py = dsu_find(y);
    if(px == py){
        return false;
    }
    if(dsu_size[px] < dsu_size[py]){
        swap(px, py);
    }    
    parent[py] = px;
    dsu_size[px] += dsu_size[py];
    return true;
}

struct edge{
    int x; int y; int w;
    bool operator < (const edge& b) const {
        return w > b.w;
    }
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    priority_queue<edge> edges;
    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            int w; cin >> w;
            edges.push({i, j, w});
        }
    }
    vvi ans(N+1);
    for(int i=1;i<=N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }   
    int cnt = 0;
    while(!edges.empty() && cnt < N - 1){
        edge e = edges.top();
        edges.pop();
        if(dsu_union(e.x, e.y)){
            ans[e.x].push_back(e.y);
            ans[e.y].push_back(e.x);
            cnt++;
        }
    }
    for(int i=1;i<=N;i++){
        sort(ans[i].begin(), ans[i].end());
        cout << ans[i].size() << " ";
        for(int x: ans[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}     
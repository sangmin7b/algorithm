#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

#define SZ 101000

int N, M;
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
    int x; 
    int y;
    int w;
};

auto cmp = [](edge &lhs, edge &rhs) -> bool {
    return lhs.w > rhs.w;
};

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);
    for(int i=1;i<=N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }
    for(int i=0;i<M;i++){
        int x, y, w;
        cin >> x >> y >> w;
        pq.push({x, y, w});
    }
    int ans = 1;
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        if(!dsu_union(e.x, e.y) || ans != e.w){
            break;
        }
        ans++;
    }
    cout << ans;
    return 0;
}     
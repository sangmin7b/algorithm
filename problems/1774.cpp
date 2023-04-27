#include<bits/stdc++.h>
#define SZ 1000

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int dsu_size[SZ];
int parent[SZ];

int dsu_find(int x){
    if(parent[x] != x){
        parent[x] = dsu_find(parent[x]);
    }
    return parent[x];
}

void dsu_union(int x, int y){
    int px = dsu_find(x);
    int py = dsu_find(y);
    if(px == py){
        return;
    }
    if(dsu_size[px] < dsu_size[py]){
        swap(px, py);
    }    
    parent[py] = px;
    dsu_size[px] += dsu_size[py];
}

ll X[SZ];
ll Y[SZ];
struct edge{
    int x; 
    int y;
    ll w;
    bool operator < (const edge& b) const {
        return w > b.w;
    }
};
ll dist(int i, int j){
    return (X[i]-X[j]) * (X[i]-X[j]) + (Y[i]-Y[j]) * (Y[i]-Y[j]);
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }
    priority_queue<edge> edges;
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            edges.push({i, j, dist(i, j)});
        }
    }
    int cnt = 0;
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(dsu_find(a) != dsu_find(b)){
            dsu_union(a, b);
            cnt++;
        }
    }
    double ans = 0;
    while(cnt < N-1){
        edge e = edges.top();
        edges.pop();
        if(dsu_find(e.x) == dsu_find(e.y)){
            continue;
        }
        dsu_union(e.x, e.y);
        cnt++;
        ans += sqrt(e.w);
    }    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}     
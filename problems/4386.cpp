#include<bits/stdc++.h>
#define SZ 100
using namespace std;

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
    if(dsu_size[px] < dsu_size[py]){
        swap(px, py);
    }
    parent[py] = px;
    dsu_size[px] += dsu_size[py];
}

double X[100];
double Y[100];
struct edge{
    int x; 
    int y;
    double w;
    bool operator < (const edge& b) const {
        return w > b.w;
    }
};
double dist(int i, int j){
    return (X[i]-X[j]) * (X[i]-X[j]) + (Y[i]-Y[j]) * (Y[i]-Y[j]);
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }    
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
    }
    priority_queue<edge> edges;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            edges.push({i, j, dist(i,j)});            
        }
    }
    int cnt = 0;
    double ans = 0;
    while(cnt < N - 1){
        edge e = edges.top();
        edges.pop();
        if(dsu_find(e.x) == dsu_find(e.y)){
            continue;
        }
        dsu_union(e.x, e.y);
        ans += sqrt(e.w);
        cnt++;
    }
    cout << ans;
    return 0;
}     
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int N, M;

#define SZ 100000

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
    return 0;
}     
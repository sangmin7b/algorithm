#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

#define SZ 200'005

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

struct query{
    int i, j, eq;
};

void solve(){
    int N; cin >> N;
    for(int i = 0; i < 200'005; i++){
        dsu_size[i] = 1;
        parent[i] = i;
    }
    vector<query> queries(N);
    vector<int> instances;
    map<int, int> rank;
    for(auto &q: queries){
        cin >> q.i >> q.j >> q.eq;
        instances.push_back(q.i);
        instances.push_back(q.j);
    }
    instances.resize(unique(instances.begin(), instances.end()) - instances.begin());
    for(int i = 0; i < instances.size(); i++){
        rank[instances[i]] = i;
    }
    for(auto &q : queries){
        if(!q.eq) continue;
        dsu_union(rank[q.i], rank[q.j]);
    }
    bool ok = true;
    for(auto &q : queries){
        if(q.eq) continue;
        ok &= (dsu_find(rank[q.i]) != dsu_find(rank[q.j]));
    }
    if(ok){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
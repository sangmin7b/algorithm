#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi dsu_size;
vi parent;

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

void solve(){
    unordered_map<string, int> name_to_idx;
    int N; cin >> N;    
    dsu_size = vi(2*N, 1);
    parent = vi(2*N,0);
    iota(parent.begin(), parent.end(), 0);
    int idx = 0;
    for(int i=0;i<N;i++){
        string a, b; cin >> a >> b;
        if(name_to_idx.count(a) == 0){
            name_to_idx[a] = idx++;
        }
        if(name_to_idx.count(b) == 0){
            name_to_idx[b] = idx++;
        }
        int idx_a, idx_b;
        idx_a = name_to_idx[a];
        idx_b = name_to_idx[b];
        dsu_union(idx_a, idx_b);
        cout << dsu_size[dsu_find(idx_a)] << "\n";
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
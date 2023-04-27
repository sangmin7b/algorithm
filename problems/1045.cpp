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
int dsu_size[1000];
int parent[1000];

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

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    vi ans(N, 0);
    priority_queue<pi, vector<pi>, greater<pi>> edges;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        for(int j=i+1;j<N;j++){
            if(s[j] == 'Y'){
                edges.push({i,j});
            }
        }
    }
    for(int i=0;i<N;i++){
        parent[i] = i;
        dsu_size[i] = 1;
    }
    if(edges.size() < M){
        cout << "-1";
        return 0;
    }
    int cnt = 0;
    int total = 0;
    while(total < M && !edges.empty()){
        auto[x, y] = edges.top();
        edges.pop();
        if(dsu_find(x) != dsu_find(y)){
            dsu_union(x, y);
            ans[x]++;
            ans[y]++;
            total++;
        }else if(cnt < M - (N - 1)){
            ans[x]++;
            ans[y]++;
            cnt++;
            total++;
        }
    }
    int p = dsu_find(0);
    for(int i=0;i<N;i++){
        if(dsu_find(i) != p){
            cout << "-1";
            return 0;
        }
    }
    for(int x: ans){
        cout << x << " ";
    }
    return 0;
}     

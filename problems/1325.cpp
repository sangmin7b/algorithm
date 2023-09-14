#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vi visited;
vi cnt;
vvi adj;
int N, M;

void bfs(int x){
    queue<int> q;
    visited = vi(N);
    q.push(x);
    visited[x] = 1;
    cnt[x]++;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int next: adj[now]){
            if(visited[next]) continue;
            visited[next] = 1;
            cnt[next]++;
            q.push(next);
        }    
    }
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    adj = vvi(N);
    cnt = vi(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }    
    for(int i = 0; i < N; i++){
        bfs(i);
    }
    int max_c = *max_element(cnt.begin(), cnt.end());
    for(int i = 0; i < N; i++){
        if(cnt[i] == max_c){
            cout << i + 1 << " ";
        }
    }
    return 0;
}     
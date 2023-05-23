#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

// N M 
// 정점1 부터 다익 
// 다른 경로가 존재한다면 
//  이미 방문한 다른 정점에서 출발한 경우밖에는없음
// 큐에 중복해서 넣으면서 경우의 수 더해주면 될 듯 
// -1은 전이됨 - 우선순위 높음, 최단 거리 업데이트할 때 경우의수도 업데이트 해주면 되는데
// 경우의 수 -1인 경우가 있다면 이전, 이후에 어떤 업데터트가 있더라도 해당 노드의 경우의 수는 -1

const int MOD = 998244353;
vector<vector<pi>> adj;
int N, M;
vl dist;
vl ans;
vi visited;
void bfs(int x){
    queue<int> q;
    visited[x] = 1;
    ans[x] = -1;
    q.push(x);
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(pi p: adj[now]){
            if(p.second != 0 || visited[p.first] || ans[p.first] == -1){
                continue;
            }
            ans[p.first] = -1;
            visited[p.first] = 1;
            q.push(p.first);
        }
    }
}

void dfs(int x, vi &stack){
    stack[x] = 1;
    for(pi p: adj[x]){
        if(p.second != 0){
            continue;
        }
        if(visited[p.first] && stack[p.first]){
            ans[p.first] = -1;                
        }
        if(!visited[p.first]){
            visited[p.first] = 1;
            dfs(p.first, stack);
        }
    }
    stack[x] = 0;
    return;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    adj = vector<vector<pi>>(N);
    dist= vl(N,1e17);
    ans = vl(N,0);
    for(int i=0;i<M;i++){
        int from, to, w;
        cin >> from >> to >> w;
        from--; to--;
        adj[from].push_back({to, w});
    }        
    dist[0] = 0;
    ans[0] = 1;
    visited = vi(N, 0);
    vi stack(N, 0);
    for(int i=0;i<N;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i, stack);
        }
    }
    visited = vi(N, 0);
    for(int i=0;i<N;i++){
        if(!visited[i] && ans[i] == -1){
            visited[i] = 1;
            bfs(i);
        }
    }
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();
        if(dist[node] < d){
            continue;
        }
        for(pi p: adj[node]){
            int next = p.first;
            ll w = p.second;
            if(d + w == dist[next]){
                if(ans[node] == -1 || ans[next] == -1){
                    ans[next] = -1;
                }else{
                    ans[next] += ans[node];
                    ans[next] %= MOD;
                }
            }else if(d + w < dist[next]){
                if(ans[node] == -1 || ans[next] == -1){
                    ans[next] = -1;
                }else{
                    ans[next] = ans[node];
                    ans[next] %= MOD;
                }
                dist[next] = d + w;
                pq.push({d+w, next});
            }
        }
    }
    for(int x: ans){
        cout << x << "\n";
    }
    return 0;
}     

/*
5 5 
1 2 3
2 3 1
3 2 0
3 4 5
2 4 5

1
1


*/
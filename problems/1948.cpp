#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piv = pair<int, vector<int>>;

int main(int argc, const char** argv) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int N, M;
    int start, end;
    cin >> N >> M;
    vector<int> nums(N,0);
    // indegree 0인 노드 업데이트하면서 최대값 & 이전 노드들 더해가면서 계산
    
    // node_num
    queue<int> q;
    // {maxval, vec:nodes}
    vector<piv> dist(N, {0, vector<int>()});
    // adj[from] == {to, w}
    vector<vector<pii>> adj(N, vector<pii>(0));
    // indegree
    vector<int> ind (N,0);  
    for(int i=0;i<M;i++){
        int from, to, d;
        cin >> from >> to >> d;
        from--; to--;
        adj[from].push_back({to, d});
        ind[to]++;
    }
    cin >> start >> end;
    start--; end--;
    dist[start] = {0, vector<int>()};
    q.push(start);
    vector<bool> visited(N,0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        for(pii next_p: adj[now]){
            int next = next_p.first;
            int d = next_p.second;
            int start_to_next = d + dist[now].first;
            if(start_to_next > dist[next].first){
                dist[next] = {start_to_next, {now}};    
            }else if(start_to_next == dist[next].first){
                dist[next].second.push_back(now);
            }
            ind[next]--;
            if(ind[next] == 0){
                q.push(next);
            }
        }
    }
    int cnt=0;
    vector<bool> visited2(N,0);
    queue<int> q2;
    q2.push(end);
    while(!q2.empty()){
        int now = q2.front();
        q2.pop();
        if(visited2[now]) continue;
        visited2[now] = true;
        for(int next: dist[now].second){
            cnt++;
            q2.push(next);
        }
    }
    cout << dist[end].first << "\n";
    cout << cnt;
    return 0;
}
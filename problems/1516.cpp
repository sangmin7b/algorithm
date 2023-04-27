#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    vi cost(N);
    vvi adj(N, vi());
    vi indegree(N, 0);
    for(int i=0;i<N;i++){
        int x; cin >> x;
        cost[i] = x;
        while(true){
            cin >> x;
            if(x == -1){
                break;
            }
            adj[x-1].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<N;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vi ans(N, 0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans[now] += cost[now];
        for(int next: adj[now]){
            ans[next] = max(ans[next], ans[now]);
            if(--indegree[next] == 0){
                q.push(next);
            }            
        }
    }
    for(int i: ans){
        cout << i << "\n";
    }
    return 0;
}
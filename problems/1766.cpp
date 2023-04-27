#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int N, M;
vvi adj;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    adj = vvi(N);
    vi indegree(N, 0);
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
        indegree[to]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<N;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.top();
        q.pop();
        cout << now + 1 << " ";
        for(int next: adj[now]){
            if(--indegree[next] == 0){
                q.push(next);
            }
        }
    }
    return 0;
}
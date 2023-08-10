#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N, M; cin >> N >> M;
    vvi adj(N);
    vi indegree(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x + 1 << " ";
        for(int next : adj[x]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    return 0;
}     
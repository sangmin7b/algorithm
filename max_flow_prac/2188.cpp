#include<bits/stdc++.h>
#define INF 1234567890
using namespace std;
using pii = pair<int, int>;
vector<vector<int>> adj;
vector<vector<int>> capacity;
vector<int> prev_node;

bool find_path(int start, int end, int N){
    queue<int> q;
    q.push(start);
    vector<int>(N, -1).swap(prev_node);
    prev_node[start] = start;
    if(start == end){
        return true;
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next: adj[now]){
            if(prev_node[next] != -1 || capacity[now][next] <= 0){
                continue;
            }
            prev_node[next] = now;
            q.push(next);
            if(next == end){
                return true;
            }
        }
    }
    return false;
}


int main(int argc, const char** argv) {
    int N, M;
    cin >> N >> M;
    adj = vector<vector<int>>(N + M + 2, vector<int>());
    prev_node = vector<int>(N + M + 2,0);
    capacity = vector<vector<int>>(N + M + 2, vector<int>(N + M + 2,0));
    for(int i=0;i<N;i++){
        int num, from, to;
        cin >> num;
        from = i + 1;
        for(int j=0;j<num;j++){
            cin >> to;
            to += N;
            capacity[from][to] = 1;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
    }
    int S, T;
    S = 0;
    T = M + N + 1;
    for(int i=0;i<N;i++){
        int to = i + 1;
        capacity[S][to] = 1;
        adj[S].push_back(to);
        adj[to].push_back(S);
    }
    for(int i=0;i<M;i++){
        int from = N + i + 1;
        capacity[from][T] = 1;
        adj[from].push_back(T);
        adj[T].push_back(from);
    }

    int flow_sum = 0;
    while(find_path(S, T, N + M + 2)){
        int min_residual = INF;
        for(int i = T; i != S; i = prev_node[i]){
            int from = prev_node[i];
            int to = i;
            min_residual = min(min_residual, capacity[from][to]);
        }
        for(int i = T; i != S; i = prev_node[i]){
            int from = prev_node[i];
            int to = i;
            capacity[from][to] -= min_residual;
            capacity[to][from] += min_residual;
        }
        flow_sum += min_residual;
    }
    cout << flow_sum;

    return 0;
}
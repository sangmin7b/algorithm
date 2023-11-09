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

int c_to_i(char c){
    return (c >'Z') ? (c - 'a') + 26 : (c - 'A');
}

int main(int argc, const char** argv) {
    int N, M;
    N = 100;

    cin >> M;
    adj = vector<vector<int>>(N, vector<int>());
    prev_node = vector<int>(N,0);
    capacity = vector<vector<int>>(N, vector<int>(N,0));
    for(int i=0;i<M;i++){
        int from, to, c;
        char f_c, t_c;
        cin >> f_c >> t_c >> c;
        from = c_to_i(f_c);
        to = c_to_i(t_c);
        capacity[from][to] += c;
        capacity[to][from] += c;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int S, T;
    S = c_to_i('A');
    T = c_to_i('Z');
    vector<int> path = vector<int>();
    int flow_sum = 0;
    while(find_path(S, T, N)){
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
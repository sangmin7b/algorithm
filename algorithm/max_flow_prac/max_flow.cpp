/* 
    ford-fulkeson method wiht dfs
*/

#include<bits/stdc++.h>
#define INF 1234567890
using namespace std;
using pii = pair<int, int>;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> capacity;


bool find_path(vector<int>& path, int start, int end){
    path.push_back(start);
    if(start == end){
        return true;
    }
    for(int next: adj[start]){
        if(visited[next] || capacity[start][next] <= 0) continue;
        visited[next] = true;
        if(find_path(path, next, end)){
            return true;
        }
    }
    path.pop_back();
    return false;
}


int main(int argc, const char** argv) {
    int N, M;
    cin >> N >> M;
    adj = vector<vector<int>>(N, vector<int>());
    visited = vector<bool>(N, 0);
    capacity = vector<vector<int>>(N, vector<int>(N,0));
    for(int i=0;i<M;i++){
        int from, to, c;
        cin >> from >> to >> c;
        capacity[from][to] = c;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int S, T;
    cin >> S >> T;
    vector<int> path = vector<int>();
    int flow_sum = 0;
    visited[S] = true;
    while(find_path(path, S, T)){
       
        int min_residual = INF;
        for(int i=0;i<path.size()-1; i++){
            int from = path[i];
            int to = path[i+1];
            min_residual = min(min_residual, capacity[from][to]);
        }
        for(int i=0;i<path.size()-1; i++){
            int from = path[i];
            int to = path[i+1];
            capacity[from][to] -= min_residual;
            capacity[to][from] += min_residual;
        }
        cout << "path: ";
        for(int p:path){
            cout << p << " ";
        }
        cout << "\n";
        cout << "flow: " << min_residual << "\n";

        flow_sum += min_residual;
        path.clear();
        vector<bool>(N,0).swap(visited);
        visited[S] = true;        
    }
    cout << flow_sum;

    return 0;
}
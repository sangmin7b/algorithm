// kosaraju
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    vector<int> rev[V];

    for(int i=0;i<E;i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        adj[from].push_back(to);
        rev[to].push_back(from);
    }
    vector<bool> visited(V, 0);
    stack<int> visit_order;
    function<void(int)> dfs = [&](int x){
        visited[x] = 1;
        for(int next: adj[x]){
            if(!visited[next]){
                dfs(next);
            }
        }
        visit_order.push(x);
        return;
    };
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    vector<bool> visited2(V, 0);
    vector<vector<int>> SCC;
    function<void(int, vector<int>&)> dfs2 = [&](int x, vector<int>& component){
        visited2[x] = 1;
        component.push_back(x);
        for(int next: rev[x]){
            if(!visited2[next]){
                dfs2(next, component);
            }
        }
        return;
    };
    while(!visit_order.empty()){
        int now = visit_order.top();
        visit_order.pop();
        if(visited2[now]){
            continue;
        }
        vector<int> component;
        dfs2(now, component);
        sort(component.begin(), component.end());
        SCC.push_back(component);
    }
    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << "\n";

    for(int i=0;i<SCC.size();i++){
        for(int j: SCC[i]){
            cout << j + 1 << " ";
        }
        cout << "-1\n";
    }


    return 0;
}

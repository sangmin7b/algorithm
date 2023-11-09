#include<bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]){
    int N, M;
    cin >> N >> M;
    vector<int> adj[2*N+1]; // 1-based
    vector<int> rev[2*N+1];
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;

        adj[N + (-a)].push_back(N + b);
        rev[N + b].push_back(N + (-a));

        adj[N + (-b)].push_back(N + a);
        rev[N + a].push_back(N + (-b));

    }

    vector<bool> visited1(2 * N + 1, 0);
    stack<int> visit_order;
    
    function<void(int)> dfs1 = [&](int x){
        visited1[x] = 1;
        for(int next: adj[x]){
            if(!visited1[next]){
                dfs1(next);
            }
        }
        visit_order.push(x);
    };
    for(int i=1;i<=N;i++){
        if(!visited1[N-i]){
            dfs1(N-i);
        }
        if(!visited1[N+i]){
            dfs1(N+i);
        }

    }
    vector<int> visited2(2 * N + 1, 0);
    vector<vector<int>> SCCs;
    function<void(int,int)> dfs2 = [&](int x, int color){
        visited2[x] = color;
        for(int next: rev[x]){
            if(!visited2[next]){
                dfs2(next, color);
            }
        }
    };
    int color = 1;
    while(!visit_order.empty()){
        int x = visit_order.top();
        visit_order.pop();
        if(visited2[x]) continue;
        dfs2(x, color);
        color++;
    }
    bool is_possible = true;
    for(int i=1;i<=N;i++){
        if(visited2[N-i] == visited2[N+i]){
            is_possible = false;
            break;
        }
    }

    if(is_possible){
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}

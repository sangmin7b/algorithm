#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    function<int(int)> oppos = [=](int n){
        return 2 * N - n;
    };
    vector<int> adj[2*N+1]; 
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

    vector<int> value(2 * N + 1, -1);
    vector<pii> v;
    for(int i=0;i< 2 * N + 1;i++){
        if(i != N){
            v.push_back({visited2[i], i});
        }
        
    }
    sort(v.begin(), v.end());
    for(pii p:v){
        int x = p.second;
        if(value[x] == -1){
            value[x] = 0;
            value[N - (x - N)] = 1;
        }
    }

    if(is_possible){
        cout << 1 << "\n";
        for(int i=1;i<=N;i++){
            cout << value[N + i] << " ";
        }
    }else{
        cout << 0;
    }

    return 0;
}

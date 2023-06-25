#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

int V, E;
int order;
vi visit_order;
vi low;
vi stack_member;
vvi adj;
vvi sccs;

stack<int> s;

int dfs(int x){
    visit_order[x] = ++order;    
    low[x] = order;
    stack_member[x] = 1;
    s.push(x);
    for(int next : adj[x]){
        if(visit_order[next] == 0){
            low[x] = min(low[x], dfs(next));
        }else if(stack_member[next]){
            low[x] = min(low[x], visit_order[next]);
        }
    }
    if(low[x] == visit_order[x]){
        vi scc;
        while(!s.empty()){
            int t = s.top(); s.pop();
            scc.push_back(t);
            stack_member[t] = 0;
            if(t == x){
                break;
            }
        }
        sccs.push_back(scc);
    }
    return low[x];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> V >> E;
    visit_order = vi(V + 1);
    low = vi(V + 1);
    stack_member = vi(V + 1);
    adj = vvi(V + 1);
    for(int i = 0; i < E; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= V; i++){
        if(visit_order[i] == 0){
            dfs(i);
        }
    }
    for(auto &scc: sccs){
        sort(scc.begin(), scc.end());
    }
    sort(sccs.begin(), sccs.end());
    cout << sccs.size() << "\n";
    for(auto scc : sccs){
        for(int x : scc){
            cout << x << " ";
        }
        cout << "-1\n";
    }
    return 0;
}     
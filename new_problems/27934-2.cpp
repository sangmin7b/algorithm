#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int MOD = 998244353;
vector<vector<pi>> adj;
int N, M;
int order;
vl dist;
vl ans;
vi visited;
vi low;
vi visit_order;
vi stack_member;
vi indegree;
vvi sccs;
stack<int> st;
map<int, int> scc_idx;
vi scc_indegree;

int dfs(int x){
    visit_order[x] = ++order;
    low[x] = visit_order[x];
    st.push(x);
    stack_member[x] = 1;
    for(auto p : adj[x]){
        auto [to, w] = p;
        if(0 < w)  continue;
        if(visit_order[to] == 0){
            low[x] = min(low[x], dfs(to));
        }else if(stack_member[to]){
            low[x] = min(low[x], visit_order[to]);            
        }
    }
    if(low[x] == visit_order[x]){ 
        vi scc;
        while(!st.empty()){
            int t = st.top(); st.pop();
            stack_member[t] = 0;
            scc.push_back(t);            
            if(t == x) break;
        }
        if(1 < scc.size()){
            sccs.push_back(scc);
        }
    }
    return low[x];
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    adj = vector<vector<pi>>(N);
    dist= vl(N,1e17);
    ans = vl(N,0);
    indegree = vi(N, 0);
    for(int i = 0; i < M; i++){
        int from, to, w;
        cin >> from >> to >> w;
        from--; to--;
        adj[from].push_back({to, w});
        if(w == 0){
            indegree[to]++;
        }
    }        
    visit_order = vi(N, 0);
    low = vi(N, 0);
    stack_member = vi(N, 0);
    for(int i = 0; i < N; i++){
        if(!visit_order[i]) dfs(i);
    }
    scc_indegree = vi(N, 0);
    dist[0] = 0;
    ans[0] = 1;
    for(int i = 0; i < sccs.size(); i++){
        vi &scc = sccs[i];
        for(int x: scc){
            ans[x] = -1;
            scc_idx[x] = i;
            for(auto[next, w] : adj[x]){
                if(low[next] == low[x] && w == 0){
                    indegree[next]--;
                }
            }
        }
        for(int x: scc){
            scc_indegree[i] += indegree[x];
        }
    }
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto[d, now] = pq.top(); pq.pop();
        // cout << now << " " << d << "\n";
        if(dist[now] < d){
            continue;
        }
        if(indegree[now] && (ans[now] != -1)){
            continue;
        }
        for(auto [next, w]: adj[now]){
            if(w == 0){
                if(scc_idx.find(now) != scc_idx.end() && scc_idx.find(now) == scc_idx.find(next)){
                    continue;
                }
                indegree[next]--;
                if(scc_idx.find(next) != scc_idx.end()){
                    scc_indegree[scc_idx[next]]--;
                }
            }
            if(dist[next] < d + w){
                continue;
            }
            if(d + w == dist[next]){
                if(ans[now] == -1 || ans[next] == -1){
                    ans[next] = -1;
                }else{
                    ans[next] += ans[now];
                    ans[next] %= MOD;
                }
            }else if(d + w < dist[next]){
                if(ans[next] != -1){
                    ans[next] = ans[now];
                }
                dist[next] = d + w;
                // cout << "next: " << next << " " << d + w << " " << indegree[next] << "\n";
            }
            if(scc_idx.find(next) != scc_idx.end()){
                // cout << "scc: " << next << " " << scc_indegree[scc_idx[next]] << "\n";
                if(scc_indegree[scc_idx[next]] != 0){
                    continue;                    
                }
                scc_indegree[scc_idx[next]] = -1;
                ll min_dist = dist[next];
                for(int x : sccs[scc_idx[next]]){
                    min_dist = min(min_dist, dist[x]);
                }
                for(int x : sccs[scc_idx[next]]){
                    dist[x] = min_dist;
                    pq.push({min_dist, x});
                }
                continue;
            }
            if(indegree[next] == 0){
                pq.push({dist[next], next});
            }            
        }
    }
    for(int x: ans){
        cout << x << "\n";
    }
    return 0;
}     
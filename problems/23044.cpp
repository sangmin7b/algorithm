#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

vvi adj;
vi target;
int N;

bool check(int k){
    vi visited(N+1, 0);
    queue<pi> q;
    for(int i=1;i<=N;i++){
        if(target[i] == 0){
            visited[i] = 1;
            q.push({i,k});
        }
    }
    vi ok(target);
    while(!q.empty()){
        auto [now, p] = q.front();
        q.pop();
        if(p == 0){
            continue;
        }
        ok[now] = 0;
        for(int next: adj[now]){
            if(visited[next]){
                continue;
            }
            visited[next] = 1;
            q.push({next, p-1});
        }        
    }
    queue<pi> q2;
    visited = vi(ok);
    for(int i=1;i<=N;i++){
        if(ok[i]){
            q2.push({i, k});
        }
    }
    while(!q2.empty()){
        auto [now, p] = q2.front();
        q2.pop();
        if(p == 0){
            continue;
        }
        if(target[now] == 1){
            ok[now] = 1;
        }else{
            return false;
        }
        for(int next: adj[now]){
            if(visited[next]){
                continue;
            }
            visited[next] = 1;
            q2.push({next, p-1});
        }   
    }
    for(int i=1;i<=N;i++){
        if(ok[i] != target[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    adj = vvi(N+1);
    target = vi(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> target[i];
    }
    for(int i=0;i<N-1;i++){
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int lo = 1, hi = N;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}     
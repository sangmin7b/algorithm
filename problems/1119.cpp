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
vi visited;
int N;

void bfs(int x){
    queue<int> q;
    visited[x] = 1;
    q.push(x);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next=0;next<N;next++){
            if(visited[next] || (adj[now][next] == 0)){
                continue;
            }
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main(int argc, const char** argv) {
    cin >> N;
    adj = vvi(N, vi(N, 0));
    bool is_possible = true;
    int edge_cnt = 0;
    for(int i=0;i<N;i++){
        string s; cin >> s;
        bool connected = false;
        for(int j=0;j<N;j++){
            if(s[j] == 'Y'){
                adj[i][j] = 1;
                edge_cnt++;
                connected = true;
            }   
       }
       is_possible = is_possible & connected;
    }
    edge_cnt /= 2;    
    int cnt = 0;
    visited = vi(N, 0);
    for(int i=0;i<N;i++){
        if(!visited[i]){
            bfs(i);
            cnt++;
        }
    }    
    if(edge_cnt < N - 1){
        is_possible = false;
    }
    if(N == 1){
        is_possible = true;
    }
    if(is_possible){
        cout << cnt - 1;
    }else{
        cout << -1;
    }
    return 0;
}     
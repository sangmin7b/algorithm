#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void solve(){
    int N;
    cin >> N;
    vi adj(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> adj[i];
    }
    vi is_cycle(N+1,0);
    vi visited(N+1,0);
    for(int i=1;i<=N;i++){
        if(visited[i]){
            continue;
        }
        int p = i;        
        while(!is_cycle[p] && (visited[p] == 0 || visited[p] == i)){
            if(visited[p] == i){
                is_cycle[p] = 1;
            }
            visited[p] = i;
            p = adj[p];            
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(!is_cycle[i]){
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(int argc, const char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}     